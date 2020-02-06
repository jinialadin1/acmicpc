#include <stdio.h>
#include<string>
#include <vector>

#include <iostream>
using namespace std;
int n, s,cnt=0;
int* arr;
void sum_arr(int sum, int depth, int end);

int main() {
	
	scanf("%d %d",&n, &s);
	
	arr = new int[n + 2]();
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	arr[n] = 0;

	for (int i = 0; i < n; i++) {
		sum_arr(arr[i], i, n-1);
	}

	printf("%d",cnt);
}


void sum_arr(int sum, int depth, int end) {
	if (depth >= end) {
	//	printf("sum=%d\n",sum);
		if (sum == s) cnt++;
		return;
	}

	sum_arr(sum + arr[depth+1], depth + 1, end);
	sum_arr(sum, depth + 1, end);
	return;
}