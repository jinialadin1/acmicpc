#include <bits/stdc++.h>
using namespace std;

void move(int n, int from, int to)
{
	int temp, middle = 0;
	
	while (from+to+middle<6)
		middle++;


	if(n==1)
	{
	    printf("%d %d\n",from, to);
		//cout<<from<<" "<<to<<endl;
	}
	else
	{
		move(n-1, from, middle);
		printf("%d %d\n",from, to);
	    //cout<<from<<" "<<to<<endl;
		move(n-1, middle, to);
	}
}

int main()
{
	int N;
	cin>>N;
	
	cout<<(int)pow(2,N)-1<<endl;
	move(N, 1, 3);
}
