#include <bits/stdc++.h>

int main(){
    //N max = 12
    int N, fac=1;
    std::cin>>N;
    if(N==0) fac=1;
    else
        while(--N)
            fac*=(N+1);
    
    std::cout<<fac<<'\n';
    return 0;
}
