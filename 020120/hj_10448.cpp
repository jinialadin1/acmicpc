#include <bits/stdc++.h>
using namespace std;
#define MAX 45
int gauss[MAX];

int main()
{
    for(int i=1;i<=MAX;++i)
        gauss[i-1] = (i*(i+1))/2; 
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int target, min_g, ret = 0;
        cin>>target;
        for(min_g = 0;gauss[min_g]<target;++min_g);
        
        for(int j=0;j<min_g;++j)
        for(int k=0;k<min_g;++k)
        for(int l=0;l<min_g;++l)
            if(gauss[j]+gauss[k]+gauss[l]==target)
            {
                ret=1; 
                break;
            }
        
        cout<<ret<<endl;
    }
}
