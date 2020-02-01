#include <iostream>
#include <string>

int main(){
	int alphabet[26];
	std::string str_in;

	//initialize alphabet array
	for(int i=0;i<26;++i) alphabet[i]=-1;

	std::getline(std::cin, str_in);
	for(int i=0;i<str_in.size();++i){
		//change alphabet to int
		int str_alp = str_in[i]-97;
		if(alphabet[str_alp]==-1) alphabet[str_alp]=i;
	}

	for(int i=0;i<26;++i)
		std::cout<<alphabet[i]<<' ';
	std::cout<<'\n';

	return 0;
}
