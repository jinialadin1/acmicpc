#include <bits/stdc++.h>

//calculate int "abcde"
int multi(int a, int b, int c, int d, int e){
    return 10000*a+1000*b+100*c+10*d+e;
}

int next666(int next){
    std::vector<int> list666;
    
    //find all 666 list with max 7 digit because next max is 10000
    for(int i=0;i<10;++i)
    for(int j=0;j<10;++j)
    for(int k=0;k<10;++k)
    for(int l=0;l<10;++l){
        list666.push_back(multi(i*100,j*100,k*100,l*100,666));
        list666.push_back(multi(i*100,j*100,k*100,666,l));
        list666.push_back(multi(i*100,j*100,666,k,l));
        list666.push_back(multi(i*100,666,j,k,l));
        list666.push_back(multi(666,i,j,k,l));
    }
    
    //sort and eliminate duplication
    sort(list666.begin(), list666.end());
    list666.erase(std::unique(list666.begin(),list666.end()),list666.end());
    
    return list666[next-1];
}

int main(){
    int N;
    std::cin>>N;
    
    std::cout<<next666(N)<<'\n';
    return 0;
}
