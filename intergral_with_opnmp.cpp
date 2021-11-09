#include<iostream>
#include<omp.h>

void pooth(int id, double a) {

	std:: cout << "id " << id <<"\n";
}

int main(){
	static long num_steps = 1000000;
	
	double step;
	int i; double x, pi, sum =0.0;
	step = 1.0/(double) num_steps;
	
	omp_set_num_threads(2); // here we set the number of thred which will be used 
	
	#pragma omp parallel 
	{
		
		int ID = omp_get_thread_num(); // each thread will call that function to get thier id 
		 
		
		for( i=0;i<num_steps;i++){
			x= ( i+0.5)*step;
			sum=sum + 4.0/(1.0 + x*x);
		}
	
	
		pi = step*sum;
	
	}
	
	std:: cout<<" pi is " << pi<<std:: endl;
	std:: cout<<" \n";

	return 0; 
}


