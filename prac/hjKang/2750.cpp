#include <bits/stdc++.h>

void self_sort(std::vector<int>& in_vec){
    //insertion sort
    int size = in_vec.size();
    if(size<2) return;
    else{
        for(int i=1;i<size;++i){
            int i2 = i;
            while(i2--){
                if(in_vec[i2]>in_vec[i2+1]){
                    int temp = in_vec[i2+1];
                    in_vec[i2+1] = in_vec[i2];
                    in_vec[i2] = temp;
                }
                else break;
            }
        }
        return;
    }
}

int main(){
    int N;
    std::vector<int> input;
    input.clear();
    
    std::cin>>N;
    for(int i=0;i<N;++i){
        int temp;
        std::cin>>temp;
        input.push_back(temp);
    }
    
    self_sort(input);
    
    for(int i=0;i<N;++i){
        std::cout<<input[i]<<'\n';
    }
    
    return 0;
}
