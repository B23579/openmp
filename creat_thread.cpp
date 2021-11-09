#include<iostream>
#include<omp.h>

void pooth(int id, double a) {

	std:: cout << "id " << id <<"\n";
}

int main(){
	
	
	double A[1000];
	
	omp_set_num_threads(5); // here we set the number of thred which will be used 
	
	#pragma omp parallel 
	{
		
		int ID = omp_get_thread_num(); // each thread will call that function to get thier id 
		
		pooth(ID,A[0]); // each tread will call this function 
	}
	
	// each thread will run the same the code and the same time
	
	// example to deal with, compute inter 4/(1+x^2) dx = pi using numerical analysis methods 
	

	std:: cout<<" all done"<<"\n";

	return 0; 
}

void inter(){

	static long num_steps = 1000000;
	
	double step;
	int i; double x, pi, sum =0.0;
	
	for( i=0;i<num_steps;i++){
		x= ( i+0.5)*step;
		sum=sum + 4.0/(1.0 + x*x;
	}
	pi = step*sum;
	 
}


