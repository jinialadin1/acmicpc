#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, S;
    cin>>N>>S;
    
    vector<int> arr;
    for(int i=0;i<N;++i)
    {
        int temp;
        cin>>temp;
        int l = arr.size();
        for(int j=0;j<l;++j) arr.push_back(arr[j]+temp);
        arr.push_back(temp);
    }
    
    int count=0;
    for(int i=0;i<arr.size();++i)
        if(arr[i]==S) count++;
        
    cout<<count<<endl;
    return 0;
}
