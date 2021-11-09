#include<iostream>
#include<omp.h>

#define NUM_THREADS 4
static long num_steps = 1000000; double step;

int main(){

	int i, nthreads; double pi, sum=0.0;
	step = 1.0/(double)num_steps;
	
	omp_set_num_threads(NUM_THREADS);
	
	#pragma omp parallel 
	
	{
	
		double x;
		#pragma omp for reduction(+:sum)
		
		for(i=0;i<num_steps; i++){
			x= (i+ 0.5)*step;
			sum +=4.0/(1.0 + x*x);
		}	
	}	
	pi = sum*step;
	
	std:: cout << "pi  value is "<< pi <<std:: endl;
	
	return 0;
}
