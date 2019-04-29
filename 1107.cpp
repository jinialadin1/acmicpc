#include <bits/stdc++.h>

#define MAX_BROKEN 10
#define MAX_INT 987654321

int FindMinBias(bool broken[], int target){
    //check the digit of input target channel
    int digit=0;
    for(int i=target;i>0;i/=10) digit++;
    
}

int main(){
    int Channel, num_broken, MadeChannel=0, digit=0;
    bool broken[MAX_BROKEN];
    //initialize broken[]
    for(int i=0;i<MAX_BROKEN;++i)
        broken[i]=false;
    
    std::cin>>Channel>>num_broken;
    
    //if all buttons are broken, I can only use +,- buttons
    if(num_broken==10)
        std::cout<<(int) abs(Channel-100)<<'\n';
    
    else{
        while(num_broken--){
            int temp;
            std::cin>>temp;
            broken[temp]=true;
        }
        
        
        while(temp_digit--){
            int min=MAX_INT, min_digit=-1;
            
            for(int i=0;i<10;++i){
                if(!broken[i]){
                    int temp=(int) abs(Channel-i*pow(10,temp_digit)-MadeChannel);
                    if(min>temp){
                        min=temp;
                        min_digit=i;
                    }
                }
            }
            
            MadeChannel+=min_digit*(int)pow(10,temp_digit);
        }
        std::cout<<(int) abs(Channel-MadeChannel)+digit<<'\n';
    }
    
    
    return 0;
}
