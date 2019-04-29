#include <bits/stdc++.h>

#define MAX_BROKEN 10
#define MAX_INT 987654321

int main(){
    int Channel, num_broken, MadeChannel1=0, MadeChannel2=0,MadeChannel=0, digit=0;
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
        
        //check the digit of input target channel
        for(int i=Channel;i>0;i/=10) digit++;
        
        int temp_digit=digit;
        while(temp_digit--){
            int min=MAX_INT, min_digit=-1;
            int target_digit = (Channel/(int) pow(10,temp_digit))%10;
            
            if(!broken[target_digit]){
                min_digit=target_digit;
            }
            else{
                for(int i=0;i<10;++i){
                    if(!broken[i]){
                        int temp=(int) abs(Channel-i*pow(10,temp_digit)-MadeChannel1);
                        if(min>temp){
                            min=temp;
                            min_digit=i;
                        }
                    }
                }
            }
            
            MadeChannel1+=min_digit*(int)pow(10,temp_digit);
        }
        
        temp_digit=digit-1;
        while(temp_digit--){
            int min=MAX_INT, min_digit=-1;
            int target_digit = (Channel/(int) pow(10,temp_digit))%10;
            
            if(!broken[target_digit]){
                min_digit=target_digit;
            }
            else{
                for(int i=0;i<10;++i){
                    if(!broken[i]){
                        int temp=(int) abs(Channel-i*pow(10,temp_digit)-MadeChannel2);
                        if(min>temp){
                            min=temp;
                            min_digit=i;
                        }
                    }
                }
            }
            
            MadeChannel2+=min_digit*(int)pow(10,temp_digit);
        }
        
        int bias1=abs(MadeChannel1-Channel);
        int bias2=abs(MadeChannel2-Channel);
        //MadeChannel=(abs(MadeChannel1-Channel)-abs(MadeChannel2-Channel))>0 ? MadeChannel2:MadeChannel1;
        std::cout<<std::min((int) abs(Channel-MadeChannel)+digit, (int) abs(Channel-100))<<'\n';
    }
    
    
    return 0;
}
