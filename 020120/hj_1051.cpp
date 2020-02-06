#include <bits/stdc++.h>
using namespace std;
#define MAX 50
string board[MAX];

int main()
{
    int N,M;
    string temp;
    cin>>N>>M;
    for(int i=0;i<N;++i)
        cin>>temp, board[i]=temp;
    
    int size = min(N,M);
    while(size)
    {
        int next = size-1;
        for(int i=0;i+next<N;++i)
        {
            for(int j=0;j+next<M;++j)
            {
                char corner[4];
                corner[1] = board[i][j];
                corner[2] = board[i][j+next];
                corner[3] = board[i+next][j+next];
                corner[4] = board[i+next][j];
                
                if(corner[1]==corner[2] && corner[1]==corner[3] && corner[1]==corner[4])
                {
                    cout<<size*size<<endl;
                    return 0;
                }
            }
        }
        size--;
    }
    cout<<0<<endl;
    return 0;
}
