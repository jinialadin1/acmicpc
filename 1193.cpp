#include <bits/stdc++.h>

std::pair<int, int> FindFraction(int n){
    int nth=0;
    int first, second;
    //find nth z-line
    for(;n>0;n-=(++nth));
    n+=nth;
    
    //if nth is odd, it is down-going z-line
    if(nth%2){
        first=nth+1-n;
        second=n;
    }
    //if nth is even, it is up-going z-line
    else{
        first=n;
        second=nth+1-n;
    }
    
    std::pair<int, int> answer=std::make_pair(first,second);
    return answer;
}

int main(){
    //N max = 10,000,000
    int N;
    std::cin>>N;
    
    std::cout<<FindFraction(N).first<<'/'<<FindFraction(N).second<<'\n';
    
    return 0;
}
