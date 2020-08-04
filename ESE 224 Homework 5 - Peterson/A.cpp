#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reorder(double x[], double y[], int points){
	int m,j,k,l;
	double temp;

	for(l=0;l<(points-1);l++)
	{
		j = l;
		for(k=l+1; k<points; k++)
		{
			if(x[k] < x[j])
				j=k;
		}
		temp = x[j];
		x[j] = x[l];
		x[l] = temp;
		temp = y[j];
		y[j] = y[l];
		y[l] = temp;
	}

		cout <<"\n\n\n\n\n\n";
		for(m=0;m<17;m++){
		cout << x[m] << "\t\t" << y[m]<< endl;
	}
		return;
}

int main(){

	//double angle_lift[20][20];
	double angle[20];
	double coefficient[20];
	int i(0);
	int limit(17);

	ifstream infile("tunnel.txt");
	while((infile >> angle[i] >> coefficient[i]) && !infile.eof())
	{
		i++;
		
	}

	cout << "ANGLES" <<"\t\t" <<"COEFFICIENTS" << endl <<
		"-----" <<"\t\t"<<"-----------"<<endl;
	for(i=0;i<17;i++){
		cout << angle[i] << "\t\t" << coefficient[i]<< endl;
	}
//	delete [] angle_lift;
	reorder(angle, coefficient, limit);
	return 0;
}
