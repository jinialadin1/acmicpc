#include <bits/stdc++.h>

//print total count of Hanoi process
void CountHanoi(int n){
    std::cout<<(int)pow(2,n)-1<<'\n'; 
}

//print process of Hanoi process
void HanoiProcess(int n,int from, int to){
    //base case when n is 1, 2
    if(n<2){
        std::cout<<from<<' '<<to<<'\n';
    }
    else if(n==2){
        int surplus=((from+to)*2)%3;
        if(surplus==0) surplus=3;
        std::cout<<from<<' '<<surplus<<'\n';
        std::cout<<from<<' '<<to<<'\n';
        std::cout<<surplus<<' '<<to<<'\n';
    }
    
    //f(n)=f(n-2)+f(2)
    else{
        HanoiProcess(n-2,1,3);
        std::cout<<"1 2\n";
        HanoiProcess(n-2,3,2);
        std::cout<<"1 3\n";
        HanoiProcess(n-2,2,1);
        std::cout<<"2 3\n";
        HanoiProcess(n-2,1,3);
    }
}

int main(){
    //N max is 20
    int N;
    std::cin>>N;
    
    CountHanoi(N);
    HanoiProcess(N,1,3);
    
    return 0;
}
