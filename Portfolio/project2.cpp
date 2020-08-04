#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
//specifiers for each data value in flags
#define bufferPointer 4								//flag for buffer pointer
#define bytesTransferred 1							//flag to keep track of each byte transferred
#define sem 0										//flag for semaphores (lock/unlock)
#define SIGUSR1 2									//producer signal
#define SIGUSR2 3									//consumer signal

int bufferSize;										//size of shared mem buffer
int dataSize;										//size from file 1
int file1Pointer = 0;								//file 1 pointer
int file2Pointer = 0;								//file 2 pointer
int memoryTablePointer = 0;							//pointer for the memory table

//producer function
void producer(char *buffer, char *input, int *flags){
	//while not at the end of the data
	while(file1Pointer < dataSize){
		//wait for semaphore
        while(flags[SIGUSR1] == 1 || flags[sem] != 0 || flags[bufferPointer] == bufferSize);
		//lock semaphore
        flags[sem] = 1;						
		buffer[flags[bufferPointer]++] = input[file1Pointer++];						//update the buffer from input
		flags[SIGUSR1] = 1;															//send producer signal		
		//free semaphore
        flags[sem] = 0;
		usleep(rand() % 1000);														//wait
	}
}

//consumer function
void consumer(char *buffer, char *output, int *flags){
	//while not at the end of the data
	while(file2Pointer < dataSize){
		//wait for semaphore
        while(flags[SIGUSR2] == 1 || flags[sem] == 1 || flags[bufferPointer] == 0);
		//lock semaphore
        flags[sem] = 1;
		output[file2Pointer++] = buffer[0];											//load output with next byte in buffer
		flags[SIGUSR2] = 1;															//send consumer signal
		for(int i = 0; i < flags[bufferPointer]; i++){
			buffer[i] = buffer[i + 1];
		}
		flags[bufferPointer]--;														//decrement bufferPointer
		flags[bytesTransferred]++;													//increment amount of bytes counted
		//unlock semaphore
		flags[sem] = 0;
		usleep(rand() % 1000);														//wait
	}
	//write output to file2
    FILE * file = fopen("file2", "w");
	for(int i = 0; i < dataSize; i++){
        fputc(output[i], file);
	}
   	fclose(file);
}

int main (){
	char *buffer;																	//char pointer for the buffer
	int *flags;																		//char pointer for flags
	int sharedTemp;																	//temp int for shared mem
	
	//input pointer and data size value
	char *input = NULL;
	dataSize = 0;

	FILE * inputFile = fopen("file1", "r");											//open input file

	//retrieve the size for the data
	fseek(inputFile, 0, SEEK_END); 													//go to end of file
	dataSize = ftell(inputFile);													//get data size
	char memoryTable[dataSize * 2];													//use data size to set up the memory table for producers and consumers
	char output[dataSize];															//use data size to set up the output file
	
	rewind(inputFile);																//go to start of file1
	input = (char*)malloc((dataSize) * sizeof(*input));								//point to beginning of file
	fread(input, dataSize, 1, inputFile);											//load file into buffer
	bufferSize = (dataSize / 2) + 1;												//set buffer size from the data size
	sharedTemp = shmget(IPC_PRIVATE, bufferSize * sizeof(char), IPC_CREAT | 0666);	//set up shared memory with obtained buffer size
	buffer = (char*) shmat(sharedTemp, NULL, 0);									//set buffer pointer to the shared memory	
	sharedTemp = shmget(IPC_PRIVATE, 5 * sizeof(int), IPC_CREAT | 0666);			//make 5 memory flags with temp shared memory
	flags = (int*) shmat(sharedTemp, NULL, 0);										//assign flags to shared memory
	//Set all flags to '0'
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;

	int masterPID = getpid();														//retrieve the master PID
	int identifier = -1;															//-1 for init: 0 for master/main: 1 for consumer: 2 for producer
	//forks a consumer
	fork();
	//fork into producer
   	if(getpid() == masterPID){
       	identifier = 0;
        fork();
	//consumer since not forked
	}else{										
        identifier = 1;
		consumer(buffer, output, flags);
    }
	//forked process is producer
	if(identifier != 1 && getpid() != masterPID){
       	identifier = 2;
		producer(buffer, input, flags);
    }
	if(identifier == 0) {
		//loops until all bytes are transferred
        	while(1){
				//producer
       			if(flags[SIGUSR1] == 1){					
               		flags[SIGUSR1] = 0;		
					memoryTable[memoryTablePointer++] = 'P';				
           		}
				//consumer
           		if(flags[SIGUSR2] == 1){
					flags[SIGUSR2] = 0;
               		memoryTable[memoryTablePointer++] = 'C';		
               	}
				//if all bytes from the file are transferred then break
           		if(flags[bytesTransferred] == dataSize)
               		break;
       		}
		//monitoring table for producers and consumers
        printf("Monitoring Table:\n");
		//dataSize is the file size. Each character transfer has a producer and consumer for the buffer so it is size * 2
		for (int i = 0; i < dataSize * 2; i++){
            printf("%c ", memoryTable[i]);
		}
		printf("\nFile Transfer Complete\n");
    }
    return 0;
}