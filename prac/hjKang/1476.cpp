#include <iostream>

#define EMAX 15
#define SMAX 28
#define MMAX 19

int main(){
	int E,S,M,real_year=0,tmp=-1;
	std::cin>>E>>S>>M;

/*	find year by comparing remainder
	15x+E , 28y+S , 19z+M (x,y,z is Natural number) must be same
	tmp = y , max(y)=15*19=285 so raise until 300
*/

	while(tmp++<300){
		int chk1 = SMAX*tmp+S-E;
		int chk2 = SMAX*tmp+S-M;
		if(!(chk1%EMAX) && !(chk2%MMAX)) {
			//break while when find tmp
			real_year=tmp*SMAX+S;
			break;
		}
	}
	std::cout<<real_year<<'\n';

	return 0;
		
}
