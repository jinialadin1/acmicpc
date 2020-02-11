#include <bits/stdc++.h>
using namespace std;
#define MAX 4096
char mat[MAX][2*MAX];

void tri(int height, int x, int y)
{
    if(height == 3)
	{
        mat[x][y] = '*';
        mat[x+1][y-1] = '*';
        mat[x+1][y+1] = '*';
        
        for(int i=y-2; i<y+3; i++)
            mat[x+2][i] = '*';
            
        return;
    }
    else
    {
        int h = height/2;
        tri(h, x, y);
        tri(h, x+h, y-h);
        tri(h, x+h, y+h);
    }
}

int main()
{
    int N;
    cin>>N;
    
    for(int i=0; i<N+1; i++)
        for(int j=0; j<N*2; j++)
            mat[i][j] = ' ';
    
    tri(N, 0, N-1);
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<2*N-1; j++)
            cout << mat[i][j];
        cout<<endl;
    }
}

