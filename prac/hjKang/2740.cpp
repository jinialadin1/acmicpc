#include <bits/stdc++.h>

std::vector<std::vector <int>> MulMatrix(std::vector<std::vector <int>> A, std::vector<std::vector <int>> B, int n, int m, int k){
    std::vector<std::vector <int>> answer, temp_v;
    answer.clear();
    
    for(int row=0; row<n; ++row){
        answer.push_back(std::vector<int>());
        for(int col=0; col<k; ++col){
            int temp = 0;
            for(int i=0; i<m; ++i){
                temp += A[row][i]*B[i][col]; 
            }
            answer[row].push_back(temp);
        }
    }
    return answer;
}

int main(){
    std::vector<std::vector <int>> A, B, answer;
    int N, M1, M2, K;
    std::cin>>N>>M1;
    int tmp=N;
    while(tmp--){
        A.push_back(std::vector<int>());
        for(int i=0; i<M1; ++i){
            int temp;
            std::cin>>temp;
            A[N-tmp-1].push_back(temp);
        }
    }
    
    std::cin>>M2>>K;
    //check for the wrong input
    if(M1!=M2) return 0;
    
    while(M2--){
        B.push_back(std::vector<int>());
        for(int i=0; i<K; ++i){
            int temp;
            std::cin>>temp;
            B[M1-M2-1].push_back(temp);
        }
    }
    
    answer = MulMatrix(A, B, N, M1, K);
    
    //print answer
    int row = answer.size(), col = answer[0].size();
    for(int i=0; i<row; ++i){
        for(int j=0; j<col-1; ++j){
            std::cout<<answer[i][j]<<' ';
        }
        if(col==1)
            std::cout<<answer[i][0]<<'\n';
        else
            std::cout<<answer[i][col-1]<<'\n';
    }

    return 0;
}
