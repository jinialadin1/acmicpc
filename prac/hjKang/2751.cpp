#include <bits/stdc++.h>

void swap(std::vector<int>& in_vec, int i, int j){
    int temp = in_vec[i];
    in_vec[i] = in_vec[j];
    in_vec[j] = temp;
    return;
}

void self_sort(std::vector<int>& in_vec, int left, int right){
    //quick sort
    int size = in_vec.size();
    if(size<2) return;
    else{
        int pivot, f_left, f_right, temp;
        f_left = left;
        f_right = right;
        pivot = in_vec[(f_left+f_right)/2];
        
        do{
            while(in_vec[f_left]<pivot) f_left++;
            while(in_vec[f_right]>pivot) f_right--;
            if(f_right>=f_left) swap(in_vec, f_left++, f_right--);
        } while(f_right>=f_left);
        
        if(left<f_right) self_sort(in_vec, left, f_right);
        if(right>f_left) self_sort(in_vec, f_left, right);
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
    
    self_sort(input,0,input.size()-1);
    
    for(int i=0;i<N;++i){
        std::cout<<input[i]<<'\n';
    }
    
    return 0;
}
