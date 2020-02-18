#include <stdio.h>
#include <math.h>
using namespace std;

long long  swap = 0;
int** arr, n;
int cnt_minus = 0, cnt_zero = 0, cnt_plus = 0;
int divide_paper(int size, int i_idx, int j_idx);
int main() {
	scanf("%d", &n);
	arr = new int* [n + 1]();
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n + 1]();
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int res = divide_paper(n, 0, 0);
	if (res == 1)  cnt_plus++;
	if (res == 0)  cnt_zero++;
	if (res == -1)  cnt_minus++;
	printf("%d\n%d\n%d", cnt_minus, cnt_zero, cnt_plus);

	return 0;
}


int divide_paper(int size, int i_idx, int j_idx) {
	if (size == 1) {
		return arr[i_idx][j_idx];
	}

	int div_size = size / 3;
	int res_arr[4] = { 0,0,0,0 }; //res_arr[0]= -1의개수, res_arr[1]= 0의개수, res_arr[2]= 1, res_arr[3]=다 다를때

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int res = divide_paper(div_size, i_idx + i * div_size, j_idx + j * div_size);
			res_arr[res + 1]++;
		}
	}

	if (res_arr[0] == 9) return -1;
	if (res_arr[1] == 9) return 0;
	if (res_arr[2] == 9) return 1;

	cnt_minus += res_arr[0];
	cnt_zero += res_arr[1];
	cnt_plus += res_arr[2];

	return 2;
}