#include<iostream>
#include<omp.h>

/* this code is use to solve the false shearing memory*/

#define NUM_THREADS 4
static long num_steps = 1000000; double step;

int main(){

	int i, nthreads;
	step = 1.0/(double)num_steps;
	
	omp_set_num_threads(NUM_THREADS);
	
	double pi=0.0;
	
	#pragma omp parallel
	
	{
	
		int i, id, nthrds;
		double x, sum;
		
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if(id ==0) nthreads=nthrds;
		
		for(i=id;i<num_steps; i=i+nthrds)
		{
			if(i==id) sum=0.0;
			
			x= (i+ 0.5)*step;
			sum +=4.0/(1.0 + x*x);
		}
		sum = sum*step;
		
		#pragma omp atomic

		pi += sum;
	
	}
	
	std:: cout << "pi  value is "<< pi <<std:: endl;
	
	return 0;
}
