#include <cstdlib>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void readInput(char *input, char **argv);
    
int main(){
	 const int MAX_COMMAND_SIZE = 1000;	//max length of input string
	 const int NUM_ARGS = 64;	//max number of arguments in a string
	 const char *exiting = "exit";	//exit string

	 int    processStatus;	//process status
	 pid_t  processId;	//process id
     char  input[MAX_COMMAND_SIZE]; //input line            
     char  *argv[NUM_ARGS]; 	   //arguments   
	 ofstream outfile;
	ifstream infile;
	std::string inputData;

	 //Infinite loop to prompt the user until exit
     while(true) {   
		  //Prompts the user for input and then gets the arguments from it
		  printf("\n");
          printf("$ ");     
          gets(input); 
          readInput(input, argv);      
		  //If the first command is 'exit' then exit the program
		  if (strcmp(argv[0], exiting) == 0){  
			     exit(0);            
		  }
		  //Iterates through the arg array until there are no more arguments
		  //Then the array breaks and the process can be executed
		  for(int i = 0; i < (sizeof(argv)/sizeof(*argv)) - 1; i++){
			  if(argv[i+1] == 0){
				  break;
			  }
		  }
		for(int i = 0; i < (sizeof(argv)/sizeof(*argv)) - 1; i++){
			 if(strcmp(argv[i],">") == 0){
						outfile.open(argv[i+1]);
						outfile << *argv;
						outfile.close();
			 }
				  if(argv[i+1] == 0){
					  break;
				  }
			  }

		 //Try to fork a child process. Throws an error if it fails
		 if((processId = fork()) < 0){    
			  printf("Could not fork child process");
			  exit(1);
		 }
		 //Try to execute the process. Throws an error if it fails
		 else if(processId == 0){ 
			 for(int i = 0; i < (sizeof(argv)/sizeof(*argv)) - 1; i++){
			 if(strcmp(argv[i],"<") == 0){
				
			 }
				  if(argv[i+1] == 0){
					  break;
				  }
			  }
			  if(execvp(argv[0], argv) < 0){  
				  printf("Could not execute process");
				  exit(1);
			  }
		 }
		 else{    
			 while(wait(&processStatus) != processId){
				 //do nothing until process completes
			 }       
		}
		
	}
}        

void readInput(char *input, char **argv){
     while(*input != '\0'){  
		 while(*input == ' '){
               *input++ = '\0';    
		 }
          *argv++ = input;        
		  while(*input != '\0' && *input != ' '){ 
               input++;           
		  }
     }
     *argv = '\0';                
}