#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int* arr, n = 1;
int divide(int left, int right);

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		arr = new int[n + 1]();
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		printf("%d\n", divide(0, n));
	}


	return 0;
}

int divide(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		int res = divide(left, mid);
		res = max(res, divide(mid + 1, right));
		/*
		분할해서 해당 구간에서 마주볼 수 있는 것들을 구하고, 가장 높은 높이를가진 토막을 return
		단, 5 5 1 1 1 5 처럼 같은것이 연속되는 경우를 감안해야함
		*/
	}
	else {
		return arr[left];
	}

}