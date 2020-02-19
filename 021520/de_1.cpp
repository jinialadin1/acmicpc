#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
3
0 0
1 100
50 0
*/
int n = 1;
vector<pair<int, int>>v;
void merge_sort(int left, int right);
void merge(int left, int right);
void merge_sort2(int left, int right);
void merge2(int left, int right);

int main() {

	scanf("%d", &n);
	v = vector<pair<int, int>>(n + 1);

	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[i].first = a;
		v[i].second = b;
	}

	//	for (int i = 0; i < n; i++) printf("%d %d\n", v[i].first, v[i].second);	
	merge_sort(0, n - 1);
	//for (int i = 0; i < n; i++) 	printf("%d %d\n", v[i].first, v[i].second);

	long long len = 9876543210;
	long long xl, yl;
	for (int i = 1; i < n; i++) {
		xl = v[i].first - v[i - 1].first;
		yl = v[i].second - v[i - 1].second;

		xl = xl * xl;
		yl = yl * yl;
		len = min(xl + yl, len);
	}

	merge_sort2(0, n - 1);
	for (int i = 1; i < n; i++) {
		xl = v[i].first - v[i - 1].first;
		yl = v[i].second - v[i - 1].second;

		xl = xl * xl;
		yl = yl * yl;
		len = min(xl + yl, len);
	}

	printf("%lld", len);

	return 0;
}

void merge_sort(int left, int right) {
	//	printf("ms %d %d\n",left,right);
	int mid = (left + right) / 2;
	if (left < right) {
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}

void merge(int left, int right) {
	int l_idx = left, r_idx = right;
	int mid = (left + right) / 2;
	int t_idx = 0;
	int m_idx = mid + 1;

	//printf("mg %d %d\n", left, right);

	vector<pair<int, int>>tmp(right - left + 1);
	while (l_idx <= mid && m_idx <= right) {
		if (v[l_idx].first < v[r_idx].first) {
			tmp[t_idx].first = v[l_idx].first;
			tmp[t_idx++].second = v[l_idx++].second;
		}
		else {
			tmp[t_idx].first = v[m_idx].first;
			tmp[t_idx++].second = v[m_idx++].second;
		}

	}

	while (l_idx <= mid) {
		tmp[t_idx].first = v[l_idx].first;
		tmp[t_idx++].second = v[l_idx++].second;
	}

	while (m_idx <= right) {
		tmp[t_idx].first = v[m_idx].first;
		tmp[t_idx++].second = v[m_idx++].second;
	}

	for (int i = 0; i <= right - left; i++) {
		//		printf("i=%d ", i);
		v[left + i].first = tmp[i].first;
		v[left + i].second = tmp[i].second;
	}
	//	printf("\n ");
}



void merge_sort2(int left, int right) {
	//	printf("ms %d %d\n",left,right);
	int mid = (left + right) / 2;
	if (left < right) {
		merge_sort2(left, mid);
		merge_sort2(mid + 1, right);
		merge2(left, right);
	}
}

void merge2(int left, int right) {
	int l_idx = left, r_idx = right;
	int mid = (left + right) / 2;
	int t_idx = 0;
	int m_idx = mid + 1;

	//printf("mg %d %d\n", left, right);

	vector<pair<int, int>>tmp(right - left + 1);
	while (l_idx <= mid && m_idx <= right) {
		if (v[l_idx].second < v[r_idx].second) {
			tmp[t_idx].first = v[l_idx].first;
			tmp[t_idx++].second = v[l_idx++].second;
		}
		else {
			tmp[t_idx].first = v[m_idx].first;
			tmp[t_idx++].second = v[m_idx++].second;
		}

	}

	while (l_idx <= mid) {
		tmp[t_idx].first = v[l_idx].first;
		tmp[t_idx++].second = v[l_idx++].second;
	}

	while (m_idx <= right) {
		tmp[t_idx].first = v[m_idx].first;
		tmp[t_idx++].second = v[m_idx++].second;
	}

	for (int i = 0; i <= right - left; i++) {
		v[left + i].first = tmp[i].first;
		v[left + i].second = tmp[i].second;
	}
}