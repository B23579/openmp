#include<iostream>

// this code should be run with the c++ compiler 

int main(){

	
	int id = omp_get_thread_num(); // this ligne give the unique identifier of each thread 
	
	std:: cout<< "Hello id "<< id<<"\n";
	std:: cout<< "Hello  id "<< id<<"\n";
	
	return 0;
}
