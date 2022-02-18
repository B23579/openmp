#include<iostream>
#include<algorithm> // for sort
#include<vector> 
#include<bits/stdc++.h> // for 2D vector and sort function 
#include<random>
#include<omp.h>

using namespace std; 

const int NDIM= 2;



int main(){
 
	vector<vector<double>> vect{};
	int m;
	int compt{0};

	cin>> m;
	int n= pow(10,m);
	
	// we want to performe  10^m iterrations 
	
	#pragma omp parallel shared(vect,n)
	{
	int rank= omp_get_thread_num(); // this return the id  of the thread
	int nthrds = omp_get_num_threads(); // return the number of thread  
	int count= n/nthrds;
	int start = start*count;
	int stop = start + count;
	
	// Now let's perform the for loop 
			for(int i=start; i<stop; i++){
				 	
				srand(i);
				double a = double( rand())/double(RAND_MAX);
				srand(i+10);
				double b = double( rand())/double(RAND_MAX);
				#pragma omp critical	
				 	{ // we used critical to allow each thread to write on the shared 
				//memory, whithout its we will ends with dump core, because all the thread
				// will try to write on the same memory at the same times. 
				// so, this imply only one thread can be at the critical region, other
				// wait their turn. 
					vect.push_back({a,b});
					}
			}
	}
	cout<< " vect size " <<vect.size()<<endl;
;
	cout<< " Done .."<<endl;	
	return 0;
	}
