#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long int histo[100001];

long long int divide(int left, int right) {
	if (left == right) {
		return histo[left];
	}

	int mid = (left + right) / 2;
	long long res = max(divide(left, mid), divide(mid + 1, right));
	int lo = mid;
	int hi = mid + 1;
	long long int h = min(histo[lo], histo[hi]);
	res = max(res, h * 2);
	while (lo > left || hi < right) {
		if (hi < right && (lo == left || histo[lo - 1] < histo[hi + 1])) {
			++hi;
			h = min(h, histo[hi]);
		}
		else {
			--lo;
			h = min(h, histo[lo]);
		}
		res = max(res, h * (hi - lo + 1));
	}
	return res;
}
int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) 
			break;
		for (int i = 0; i < n; i++) 
			cin >> histo[i];
		cout << divide(0, n-1) << endl;
	}
	return 0;
}