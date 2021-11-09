#include<iostream>
#include<omp.h>

#define PAD 8 // assume 64 byte l1ne size

#define NUM_THREADS 4
static long num_steps = 1000000; double step;

int main(){

	int i, nthreads; double pi, sum[NUM_THREADS][PAD];
	step = 1.0/(double)num_steps;
	
	omp_set_num_threads(NUM_THREADS);
	
	#pragma omp parallel
	
	{
	
		int i, id, nthrds;
		double x;
		
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if(id ==0) nthreads=nthrds;
		
		for(i=id;i<num_steps; i=i+nthrds)
		{
			if(i==id) sum[id][0]=0.0;
			
			x= (i+ 0.5)*step;
			sum[id][0]+=4.0/(1.0 + x*x);
		}
	
	}
	
	pi=0.0;
	for(i=0;i<nthreads;i++) pi += sum[i][0]*step;
	
	std:: cout << "pi  value is "<< pi <<std:: endl;
	
	return 0;
}
