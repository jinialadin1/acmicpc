#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<fixed;
    cout.precision(3);
    float answer, tot=153.0;
    vector<pair<int, int>> cases;
    int card1, card2, score, low=0;
    
    cin>>card1>>card2;
    if(card1==card2) card2+=10;
    score = (card1+card2)%10;
    for(int i=1;i<20;++i)
    {
        for(int j=i+1;j<=20;++j)
        {
            if(i==card1 || i==card2 || j==card1 || j==card2) continue;
            else cases.push_back(make_pair(i,j));
        }
    }
    
    if(card1==card2-10) answer = (tot-10+card1)/tot;
    else
    {
        for(int i=0;i<tot;++i)
        {
            int comp1 = cases[i].first, comp2 = cases[i].second, compScore = (comp1+comp2)%10;
            if(compScore<score && comp1!=comp2-10) low++;
        }
        answer = ((float) low)/tot;
    }
    cout<<answer<<endl;
    return 0;
}
