#include<bits/stdc++.h>

int countz(int n, int r, int c){
    int count=0;
    int tempn=n+1;
    bool rquad=true, cquad=true; //[0,2^(n-1)) -> true, [2^(n-1),2^n) -> false
    
    while(--tempn){
        int zcount;
        
        //find quardrant as z course
        rquad=r<((int) pow(2,tempn-1))?true:false;
        cquad=c<((int) pow(2,tempn-1))?true:false;
        if(rquad&&cquad) zcount=0;
        else if(rquad&&(!cquad)) zcount=1;
        else if((!rquad)&&cquad) zcount=2;
        else zcount=3;
        
        //count the largest quardrant
        count+=((int) pow(4,tempn-1))*zcount;
        
        //zoom into the next largest quardrant
        r=rquad?r:r-((int) pow(2,tempn-1));
        c=cquad?c:c-((int) pow(2,tempn-1));
    }
    
    return count;
}

int main(){
    //N max is 15, 0 <= r, c < 2^N
    int N, r, c;
    std::cin>>N>>r>>c;
    
    std::cout<<countz(N,r,c)<<'\n';
    
    return 0;
}
