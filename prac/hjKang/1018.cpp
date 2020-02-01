#include<bits/stdc++.h>

#define MAXSIZE 50
#define CHESSSIZE 8

//MinCountCHangeColor calculate the min color change when cut the chess board in (pos_x, pos_y)
int MinCountChangeColor(int board[MAXSIZE][MAXSIZE],int pos_x, int pos_y,int MaxN, int MaxM){
    const int MaxInt=987654321;
    if(pos_x+CHESSSIZE>MaxN) return MaxInt;
    if(pos_y+CHESSSIZE>MaxM) return MaxInt;
    
    //check two kind of chess board.
    //color_std1 and count1 check for the board color start with WHITE
    //color_std2 and count2 check for the board color start with BLACK
    int color_std1=0, color_std2=1;
    int count1=0, count2=0;
    for(int i=pos_x;i<pos_x+CHESSSIZE;++i){
        for(int j=pos_y;j<pos_y+CHESSSIZE;++j){
            if(board[i][j]!=color_std1) count1++;
            if(board[i][j]!=color_std2) count2++;
            color_std1++;
            color_std1%=2;
            color_std2++;
            color_std2%=2;
        }
        color_std1++;
        color_std1%=2;
        color_std2++;
        color_std2%=2;
    }
    
    return std::min(count1,count2);
}

int main(){
    int board[MAXSIZE][MAXSIZE];
    int N,M;
    char temp;
    
    for(int i=0;i<MAXSIZE;++i)
    for(int j=0;j<MAXSIZE;++j)
        board[i][j]=-1;
    
    std::cin>>N>>M;
    for(int i=0;i<N;++i)
    for(int j=0;j<M;++j){
        std::cin>>temp;
        //white -> 0, black -> 1
        board[i][j] = temp=='B'? 1 : 0;
    }
    
    
    int count, min_count;
    min_count=987654321;
    for(int i=0;i+CHESSSIZE<=N;++i)
    for(int j=0;j+CHESSSIZE<=M;++j){
        count=MinCountChangeColor(board, i, j, N, M);
        min_count = std::min(min_count, count);
    }
    std::cout<<min_count<<'\n';
    
    return 0;
    
}
