#include <stdio.h>
#include <vector>
using namespace std;
vector<int> T;
bool find_ans = false;
void sum_arr(int key, int sum, int depth);

int main()
{
	T = vector<int>(100);
	for (int i = 1; i < 45; i++) {
		T[i] =  i* (i + 1) / 2;
	}
	int tc, key;
	scanf("%d",&tc);

	while (tc--) {
		find_ans = false;		
		scanf("%d",&key);
		sum_arr(key, 0, 0);
		if (find_ans == true) printf("1\n");
		else printf("0\n");
	}
	return 0;
}

void sum_arr(int key, int sum, int depth) {
	if (sum > key )  return;
	if (depth == 3) {
	//	printf("sum=%d \n",sum);
		if (key == sum) {
			find_ans = true;
			return;
		}
		return;
	}

	for (int i = 1; i < 45; i++) {
		sum_arr(key, sum +T[i], depth + 1);
	}
	
	return;
}