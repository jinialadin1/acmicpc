#include <bits/stdc++.h>

long long int findgcd(long long int a, long long int b){
    if(b==0)
        return a;
    return findgcd(b, a%b);
}

int main(){
    long long int a, b, c;
    std::cin>>a>>b;
    if(a>b)
        c = findgcd(a,b);
    else
        c = findgcd(b,a);
        
    for(long long int i=0; i<c; ++i){
        std::cout<<'1';
    }
    std::cout<<'\n';
    
    return 0;
}
