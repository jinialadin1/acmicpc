#include <bits/stdc++.h>

long long int findgcd(long long int a, long long int b){
    if(b==0)
        return a;
    return findgcd(b, a%b);
}

int main(){
    std::string in_str;
    long long int a = 0, b = 0, c, i=0;
    std::getline(std::cin, in_str);

    while(true){
        if(in_str[i]==':')
            break;
        a = 10*a+(in_str[i++]-48);
    }
    while(++i < in_str.size()){
        b = 10*b+(in_str[i]-48);
    }
    
    if(a>b)
        c = findgcd(a,b);
    else
        c = findgcd(b,a);
        
    std::cout<<a/c<<":"<<b/c<<'\n';
    
    return 0;
}
