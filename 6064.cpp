#include <bits/stdc++.h>

//check every (x-y + M*z , int z<N) year that is divded by n
//that will be the true year
int FindYear(int M, int N, int x, int y){
    int fn_x = 0, fn_y = 0, fn_year = -1;
    
    for(int i=0; i<N; ++i){
        if((M*i+x-y)%N==0){
            fn_year = M*i+x;
            break;
        }
    }
    return fn_year;
}

int main(){
    int M, N, x, y, temp;
    std::cin>>temp;
    while(temp--){
        std::cin>>M>>N>>x>>y;
        std::cout<<FindYear(M,N,x,y)<<'\n';
    }
    
    return 0;
}
