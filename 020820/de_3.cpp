#include <stdio.h>
#include <math.h>
using namespace std;
void merge(int left, int right, int* arr);
void merge_sort(int left, int right, int* arr);

long long  swap = 0;
int* temp_arr, *arr;
int main() {
	int n;
	scanf("%d",&n);
	arr = new int[n + 1]();
	temp_arr = new int[n + 1]();

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	merge_sort(0, n-1, arr);
	printf("%lld", swap);
	return 0;
}

void merge_sort(int left, int right, int* arr) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid, arr);
		merge_sort(mid + 1, right, arr);
		merge(left, right, arr);
	}
}

void merge(int left, int right, int* arr) {
	int inital_left = left, inital_right = right;
	int inital_mid = (left + right) / 2;
	int idx = left;
	int mid = inital_mid + 1;
	while (left <= inital_mid && mid <= right) {
		if (arr[left] <= arr[mid]) {
			temp_arr[idx++] = arr[left++];
		}
		else {
			temp_arr[idx++] = arr[mid++];
			swap+=(inital_mid -left)+1;
		}
	}

	while (left <= inital_mid) {
		temp_arr[idx++] = arr[left++];
	}

	while (mid <= right) {
		temp_arr[idx++] = arr[mid++];
		swap += (inital_mid - left) + 1;
	}

	for (int i = inital_left; i <= inital_right; i++) arr[i] = temp_arr[i];
}