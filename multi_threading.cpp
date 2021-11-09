#include<iostream>

#include<omp.h>
#include<map>
#include<string> 

// Multithreading example 

void function1(char symbol){
	for(int i=0;i<200; i++) std:: cout<< symbol;
}

void function2(){
	for(int i=0;i<200; i++) std:: cout<< "-";
}
 
 
void RefreshForcast(std:: map<std:: string, int> forecastMap) {

	for(auto item :: forecastMap){
		item.second++;
		std::cout<<item.first<<"-" << item.second << std :: endl;
		}
		
		

}


int main(){
	std:: map<std:: string, int> forecastMap = {{"new York" , 15},{"Trieste",20}, {"Berllin", 23}}

	#pragma omp parallel 
	{
		#pragma omp sections 
		{
			#pragma omp section 
			function1('o');
			
			#pragma omp section 
			
			function2();
		
		}
		}
	return 0;
}
