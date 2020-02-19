#include <bits/stdc++.h>
#define MAX 500000
using namespace std;
long line[MAX];

int countPair(int start, int end)
{
    if(start==end || start>end) return 0;
    if(start+1==end) return 1;
    
    int mid = (start+end)/2;
    int ret = countPair(start,mid-1) + countPair(mid+1,end);
    if(mid!=start) ret++;
    if(mid!=end) ret++;
    
    int midVal = line[mid];
    vector<int> left, right;
    int highLeft = midVal, highRight = midVal;
    left.clear(), right.clear();
    for(int i=mid-1;i>=start;--i)
    {
        if(line[i]>=highLeft)
        {
            left.push_back(i);
            highLeft = line[i];
        }
    }
    for(int i=mid+1;i<=end;++i)
    {
        if(line[i]>=highRight)
        {
            right.push_back(i);
            highRight = line[i];
        }
    }
    int leftCount = left.size(), rightCount = right.size();
    
    for(int i=0;i<leftCount;++i)
    {
        if(mid-left[i]==1) continue;
        if(i==0) ++ret;
        else if(line[left[i-1]]>midVal) break;
        else ++ret;
    }
    
    for(int i=0;i<rightCount;++i)
    {
        if(right[i]-mid==1) continue;
        if(i==0) ++ret;
        else if(line[right[i-1]]>midVal) break;
        else ++ret;
    }
    
    int leftI=0, rightI=0;
    while(leftI<leftCount && rightI<rightCount)
    {
        if(line[left[leftI]]>line[right[rightI]])
            ++ret, ++rightI;
        else if(line[left[leftI]]<line[right[rightI]])
            ++ret, ++leftI;
        else
        {
            int count=1;
            if(leftI<leftCount-1) ++count, ++leftI;
            if(rightI<rightCount-1) ++count, ++rightI;
            ret+=count;
        }
    }
    return ret;
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>line[i];
    
    cout<<countPair(0,N-1)<<endl;
}
