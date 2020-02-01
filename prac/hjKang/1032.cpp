#include <iostream>
#define MAXLEN 60

int main(){
	std::cin.tie(NULL);

	int T;
	char in1[52][MAXLEN], output[MAXLEN];
	
	std::cin>>T;
	int T_bp=T;
	while(T_bp--){
		scanf("%200s",in1[T_bp]);
	}


	if(T==1){
		for(int i=0;in1[0][i]!='\0';++i) std::cout<<in1[0][i];
		std::cout<<'\n';
	}
	else{
		int len=0;
		for(;in1[0][len]!='\0';++len) output[len]=in1[1][len];
		while(T--){
			for(int i=0;i<len;++i){
				if(output[i]!=in1[T][i]) output[i]='?';
			}
		}
		for(int i=0;i<len;++i) std::cout<<output[i];
		std::cout<<'\n';
	}

	return 0;
}
