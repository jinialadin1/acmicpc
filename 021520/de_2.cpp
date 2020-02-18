#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long  swap = 0;
int *arr, n=1;
int cnt_minus = 0, cnt_zero = 0, cnt_plus = 0;
long long divide(int left, int right);

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		arr = new int[n + 1]();
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		printf("%lld\n",divide(0,n));
		delete[] arr;
	}
	

	return 0;
}

long long divide(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		long long res = divide(left, mid);
		res = max(res, divide(mid+1,right));

		int min_h = min(arr[mid], arr[mid+1]);
		long long res2 = 2*min_h;
		int l_idx = mid, r_idx = mid + 1;

		while (left < l_idx && r_idx < right) {
		//	printf("l=%d r=%d",l_idx,r_idx);
			if (arr[l_idx-1] > arr[r_idx+1]) {
				min_h = min(min_h, arr[l_idx-1]);
				res2 = max(res2, (long long)min_h*(r_idx - (l_idx-1) + 1));
				l_idx--;
			}
			else {
 				min_h = min(min_h, arr[r_idx+1]);
				res2 = max(res2, (long long)min_h * ((r_idx+1) - l_idx + 1));
				r_idx++;
			}
	//		printf(" l=%d r=%d %lld\n",l_idx, r_idx, res2);
		}

		while (left < l_idx) {
			min_h = min(min_h, arr[l_idx-1]);
			res2 = max(res2, (long long)min_h * (r_idx - (l_idx-1) + 1));
			l_idx--;
		}

		while (r_idx < right) {
			min_h = min(min_h, arr[r_idx+1]);
			res2 = max(res2, (long long)min_h * ((r_idx+1) - l_idx + 1));
			r_idx++;
		}

		return max(res, res2);
	}
	else {
		return arr[left];
	}

}