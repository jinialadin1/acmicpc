#include <bits/stdc++.h>
using namespace std;
#define MAX 500000

int arr[MAX], cmparr[MAX];

//start <= x <= end
long long sort(int start, int end)
{
    if(start==end) return 0;
    
    int mid = (start+end)/2;
    long long ret = sort(start,mid)+sort(mid+1, end);
    
    for(int i=start, j=mid+1, k=0; i<=mid || j<=end;)
    {
        if(i<=mid && (j>end || arr[i]<=arr[j]))
            cmparr[k++] = arr[i++];
        else
        {
            ret += (long long)(mid-i+1);
            cmparr[k++] = arr[j++];
        }
    }
    
    for(int i=start;i<=end;++i)
        arr[i] = cmparr[i-start];
    
    return ret;
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
	    cin>>arr[i];
	    
	 cout<<sort(0, N-1);
}
