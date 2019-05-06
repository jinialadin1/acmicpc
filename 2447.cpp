#include<bits/stdc++.h>

void findstar(int x, int y){
    while(x>0){
        if(x%3==1 && y%3==1){
            std::cout<<' ';
            return;
        }
        x/=3;
        y/=3;
    }
    std::cout<<'*';
}

void printstar(int n){
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            findstar(x,y);
        }
        std::cout<<'\n';
    }
}

int main(){
    //N = 3^k, k=[1,8);
    int N;
    std::cin>>N;
    printstar(N);
    
    return 0;
}
