#include <iostream>
#define MAX 30

int main()
{
    int Testcase=0, N=0, M=0;
    long long int comb[MAX][MAX];
    for(int i=0;i<MAX;++i) comb[0][i]=i+1;
    
    for(int i=1;i<MAX;++i){
    for(int j=i;j<MAX;++j){
        long long int temp=0;
        for(int k=i-1;k<j;++k) temp+=comb[i-1][k];
        comb[i][j]=temp;
    }}
    
    std::cin>>Testcase;
    if(Testcase>0){
        for(int i=0;i<Testcase;++i){
            std::cin>>N>>M;
            std::cout<<comb[N-1][M-1]<<std::endl;
        }
    }
    else return -1;
    return 0;
}
