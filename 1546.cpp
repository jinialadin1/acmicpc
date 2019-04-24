#include <iostream>

#define NMAX 1001

int main(){
	int N;
	double score[NMAX], avr=0, max_score=0;
	
	std::cin>>N;
	for(int i=0;i<N;++i){
		std::cin>>score[i];
		max_score=std::max(max_score,score[i]);
	}
	for(int i=0;i<N;++i){
		score[i]=score[i]/max_score*100;
		avr+=score[i];
	}
	std::cout.precision(10);
	std::cout<<avr/N<<'\n';

	return 0;
}
