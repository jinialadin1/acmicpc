#include <iostream>

int main(){
	int white[100][100], N, sqx, sqy, tot=0;
	
	//initialize white
	for(int x=0; x<100; ++x)
	for(int y=0; y<100; ++y)
		white[x][y]=0;

	std::cin>>N;
	for(int i=0;i<N;++i){
		std::cin>>sqx>>sqy;
		sqx-=1;
		sqy-=1;
		for(int x=0;x<10;++x)
		for(int y=0;y<10;++y)
			white[sqx+x][sqy+y]=1;
	}
	for(int x=0;x<100;++x)
	for(int y=0;y<100;++y)
		if(white[x][y]) tot++;
	std::cout<<tot<<'\n';

	return 0;
}
