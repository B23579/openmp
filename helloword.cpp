#include<iostream>
#include<omp.h>

int main(){

	#pragma omp parallel /*THIS INSTRUCTION REQUEST SOME THREAD and also specify that all the code between 
	the brachets is part of an openMP parallel section*/
	
	{
		int id = omp_get_thread_num(); // this ligne give the unique identifier of each thread 
		
		std:: cout<< "Hello world "<< id<<"\n";
		std:: cout<< "Hello  world "<< id<<"\n";
	}
	return 0;
	
	/* we comonly use g++ helloword.cpp -o helloworld to compile the c++ programm, 
	when using openMP, we sould ad -fopenmp in the syntaxe as follow
	g++ -fopenmp helloword.cpp -o helloworld : this will produce the executable hello_openmp*/
	
	// the program will be split in four tread and each print hello word.  
}


