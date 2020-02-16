#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int fence[MAX];

long long solve(int left, int right)
{
    if(left==right) return fence[left];
    int mid = (left+right)/2;
    
    long long ret = max(solve(left,mid), solve(mid+1, right));
    
    int lo = mid, hi = mid+1;
    int height = min(fence[lo], fence[hi]);
    
    ret = max(ret, (long long) height*2);
    while(left<lo || hi<right)
    {
        if(hi<right && (lo==left || fence[lo-1]<fence[hi+1]))
        {
            ++hi;
            height = min(height, fence[hi]);
        }else
        {
            --lo;
            height = min(height, fence[lo]);
        }
        ret = max(ret, (long long) height*(hi-lo+1));
    }
    return ret;
}

int main()
{
    int N;

    cin>>N;
    while(N!=0)
    {
        for(int i=0;i<N;++i)
            cin>>fence[i];
            
        cout<<solve(0,N-1)<<endl;
        
        cin>>N;    
    }
}
