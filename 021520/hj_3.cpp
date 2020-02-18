#include <bits/stdc++.h>
using namespace std;
#define MAX 2187
int paper[MAX][MAX];
int paperNum[3];

void cut(int ulx, int uly, int drx, int dry)
{
    int temp[4] = {ulx, uly, drx, dry};
    int delta = (drx-ulx)/3;
    int base = paper[ulx][uly];
    if(delta==0)
    {
        ++paperNum[base+1];
        return;
    }
    
    bool needCut = false;
    for(int i=ulx;i<drx && !needCut;++i)
    for(int j=uly;j<dry && !needCut;++j)
    {
        needCut = base==paper[i][j] ? false : true;
    }
    
    if(!needCut)
    {
        ++paperNum[base+1];
        return;
    }else
    {
        cut(ulx        , uly        , ulx+delta  , uly+delta  );
        cut(ulx+delta  , uly        , ulx+delta*2, uly+delta  );
        cut(ulx+delta*2, uly        , ulx+delta*3, uly+delta  );
        cut(ulx        , uly+delta  , ulx+delta  , uly+delta*2);
        cut(ulx+delta  , uly+delta  , ulx+delta*2, uly+delta*2);
        cut(ulx+delta*2, uly+delta  , ulx+delta*3, uly+delta*2);
        cut(ulx        , uly+delta*2, ulx+delta  , uly+delta*3);
        cut(ulx+delta  , uly+delta*2, ulx+delta*2, uly+delta*3);
        cut(ulx+delta*2, uly+delta*2, ulx+delta*3, uly+delta*3);
        return;
    }
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
        cin>>paper[i][j];
        
    cut(0,0,N,N);
    
    for(int i=0;i<3;++i)
        cout<<paperNum[i]<<endl;
    
    return 0;
}
