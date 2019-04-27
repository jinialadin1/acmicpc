#include <bits/stdc++.h>

int main(){
    int Tc, repeat_num;
    std::string in_str;
    std::cin>>Tc;
    
    while(Tc--){
        std::cin>>repeat_num;
        std::getline(std::cin,in_str);
        for(int i=1;i<in_str.size();++i){
            for(int j=0;j<repeat_num;++j){
                std::cout<<in_str[i];
            }
        }
        std::cout<<'\n';
    }
    
    return 0;
}
