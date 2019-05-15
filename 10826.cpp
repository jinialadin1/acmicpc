#include <bits/stdc++.h>

std::vector<char> fibonacci(int n){
    if(n==0) return {'0'};
    else if(n==1||n==2) return {'1'};
    
    std::vector<char> fib_n1 = {'1'};
    std::vector<char> fib_n2 = {'1'};
    std::vector<char> fib;
    
    for(int i=3;i<n+1;++i){
        fib.clear();
        int fib1_size = fib_n1.size();
        int fib2_size = fib_n2.size();
        
        int upcome=0;
        for(int i2=0;i2<fib1_size;++i2){
            int fib1, fib2, new_fib;
            fib1 = fib_n1[i2]-48;
            fib2 = i2<fib2_size?fib_n2[i2]-48:0;
            
            new_fib = fib1+fib2+upcome;
            if(new_fib>10){
                fib.push_back(new_fib+48-10);
                upcome = 1;
            }
            else{
                fib.push_back(new_fib+48);
                upcome = 0;                
            }
        }
        if(upcome)
            fib.push_back(49); //char 49 -> int 1
        
        fib_n2.clear();
        fib_n2 = fib_n1;
        fib_n1.clear();
        fib_n1 = fib;
    }
    
    return fib;
}

int main(){
    //n max = 10,000
    int n;
    std::cin>>n;
    
    std::vector<char> answer;
    answer = fibonacci(n);
    
    for(int i = answer.size()-1;i>=0;--i)
        std::cout<<answer[i];
    std::cout<<'\n';
    return 0;
}
