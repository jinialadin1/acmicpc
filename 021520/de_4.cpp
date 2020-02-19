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
		�����ؼ� �ش� �������� ���ֺ� �� �ִ� �͵��� ���ϰ�, ���� ���� ���̸����� �丷�� return
		��, 5 5 1 1 1 5 ó�� �������� ���ӵǴ� ��츦 �����ؾ���
		*/
	}
	else {
		return arr[left];
	}

}