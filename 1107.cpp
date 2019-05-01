#include <bits/stdc++.h>

#define MAX_BROKEN 10
#define MAX_INT 987654321

int main(){
    int Channel, num_broken, MadeChannelList[3]={0,0,0}, bias[3]={MAX_INT,MAX_INT,MAX_INT}, min_bias=-1, MadeChannel=0, digit=0;
    int min_possible=MAX_INT, max_possible=-1;
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
        
        for(int i=0;i<MAX_BROKEN;++i){
            if(!broken[i]){
                if(i!=0)
                    min_possible=std::min(i,min_possible);
                max_possible=std::max(i,max_possible);
            }
        }
        
        //check the digit of input target channel
        if(Channel==0) digit=1;
        for(int i=Channel;i>0;i/=10) digit++;
        
        if(digit>1){
            for(int i=0;i<3;++i){
                int temp_digit=digit+i-1;
                bool GoingWell = true;
                while(temp_digit--){
                    int min=MAX_INT, min_digit=-1;
                    int target_digit = (Channel/(int) pow(10,temp_digit))%10;
                    
                    if(!broken[target_digit] && GoingWell){
                        min_digit=target_digit;
                    }
                    else{
                        GoingWell=false;
                        for(int ii=0;ii<10;++ii){
                            if(!broken[ii]){
                                int temp=(int) abs(Channel-ii*pow(10,temp_digit)-MadeChannelList[i]);
                                if(min>temp){
                                    min=temp;
                                    min_digit=ii;
                                }
                            }
                        }
                    }
                    
                    if(i==0 && temp_digit==digit-2) min_digit=max_possible;
                    if(i==2 && temp_digit==digit && min_possible) min_digit=min_possible;
                    
                    MadeChannelList[i]+=min_digit*(int)pow(10,temp_digit);
                }
                bias[i]=(int) abs(MadeChannelList[i]-Channel);
            }
            
            min_bias=bias[2]+1<bias[1]?bias[2]:bias[1];
            if(min_bias==bias[1])
                min_bias=bias[1]+1<bias[0]?bias[1]:bias[0];
            else
                min_bias=bias[2]+2<bias[0]?bias[2]:bias[0];
    
            if(min_bias==bias[0]){
                MadeChannel=MadeChannelList[0];
                digit--;
            }
            else if(min_bias==bias[1]){
                MadeChannel=MadeChannelList[1];
            }
            else if(min_bias==bias[2]){
                MadeChannel=MadeChannelList[2];
                digit++;
            }
        }
        
        else{
            int min=MAX_INT, min_digit10=0, min_digit1=-1;
            for(int ii=0;ii<10;++ii){
                if(!broken[ii]){
                    int temp=(int) abs(Channel-ii);
                    if(min>temp){
                        min=temp;
                        min_digit1=ii;
                    }
                }
            }
            for(int i=1;i<10;++i){
                for(int ii=0;ii<10;++ii){
                    if(!broken[ii] && !broken[i]){
                        int temp=(int) abs(Channel-ii-10*i);
                            if(min>temp){
                                min=temp;
                                min_digit1=ii;
                                min_digit10=i;
                            }
                    }
                }
            }
            
            if(min_digit10!=0) digit++;
            min_bias=min;
        }
        
        
        std::cout<<std::min(min_bias+digit, (int) abs(Channel-100))<<'\n';
    }
    
    
    return 0;
}
