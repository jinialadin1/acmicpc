#include <bits/stdc++.h>

int main(){
    int N, count5;
    //N max = 500
    std::cin>>N;
    count5 = N/5+N/25+N/125;
    std::cout<<count5<<'\n';
    return 0;
}
