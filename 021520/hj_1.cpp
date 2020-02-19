#include<bits/stdc++.h>
using namespace std;

struct dot
{
	int x,y;
	dot(int ix, int iy) : x(ix), y(iy) {};
};

vector<dot> dots;

long dist(const dot &i, const dot &j)
{
	return (i.x-j.x)*(i.x-j.x) + (i.y-j.y)*(i.y-j.y);
}

bool cmp(const dot &p1, const dot &p2)
{
	return p1.x < p2.x;
}

bool cmp2(const dot &p1, const dot &p2)
{
	return p1.y < p2.y;
}

long closest(int start, int end)
{
	if(end<=start) return 987654321;
    if(end-start==1) return dist(dots[start], dots[end]);
    if(end-start==2) return min({dist(dots[start], dots[end]), dist(dots[start+1], dots[end]), dist(dots[start], dots[end-1])});
    
	int mid = (end + start) / 2;
	long ret = min(closest(start, mid), closest(mid+1, end));
	
	vector<dot> temp;
	for(int i=start; i<mid+1; ++i)
	{
		long d = (dots[i].x-dots[mid].x)*(dots[i].x-dots[mid].x);
		if(d<ret) temp.push_back(dots[i]);
	}
	for(int i=mid+1; i<end+1; ++i)
	{
		long d = (dots[i].x-dots[mid+1].x)*(dots[i].x-dots[mid+1].x);
		if(d<ret) temp.push_back(dots[i]);
	}
	
	sort(temp.begin(), temp.end(), cmp2);
	int tempSize = temp.size();
	for(int i=0;i<tempSize-1;++i)
	{
		for(int j=i+1;j<tempSize;++j)
		{
			long d = (temp[j].y - temp[i].y)*(temp[j].y - temp[i].y);
			if(d<ret) ret = min(ret, dist(temp[i], temp[j]));
			else break;
		}
	}
	return ret;
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int x, y;
        cin>>x>>y;
        dots.push_back(dot(x,y));
    }
    
    sort(dots.begin(), dots.end(), cmp);
    
    cout<<closest(0,N-1)<<endl;
    return 0;
}
