#include <bits/stdc++.h>

int calcBiCo(int N, int K){
    int answer = 1;
    for(int i=0;i<K;++i){
        answer = answer * (N-i) / (i+1);
    }
    return answer;
}

int main(){
    int N,K;
    std::cin>>N>>K;
    std::cout<<calcBiCo(N,K)<<'\n';
    
    return 0;
}
