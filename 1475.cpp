#include<bits/stdc++.h>

int MinSet(int n){
    if(n==0) return 1;
    
    //initialize number array that counts frequency of number
    std::vector<int> number(10,0);
    
    //count frequecny
    while(n>0){
        number[n%10]++;
        n/=10;
    }
    
    //check 6, 9
    int temp=number[6]+number[9];
    number[6]=temp/2;
    number[9]=temp-number[6];
    
    //return max used number (same as required number set)
    return *std::max_element(number.begin(),number.end());
}

int main(){
    //N max = 1,000,000
    int N;
    std::cin>>N;
    
    std::cout<<MinSet(N)<<'\n';
    return 0;
}
