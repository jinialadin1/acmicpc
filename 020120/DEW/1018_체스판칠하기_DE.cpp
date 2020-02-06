#include <stdio.h>
#include<string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int paint_board(vector<string>& s, int si, int sj);

int main() {
	
	vector<string> s;
	scanf("%d %d",&n,&m);

	s = vector<string>(n+2);
	getline(std::cin, s[0]);
	for (int i = 0; i < n; i++) {
		s[i].resize(m + 1);
		getline(std::cin, s[i]);
	}

	int min_val = 2147483647;
	for (int i = 0; i+8 <= n; i++) {
		for (int j = 0; j+8 <= m; j++) {
			int res = paint_board(s, i, j);
			min_val = min(res, min_val);
		}
	}
	
	printf("%d",min_val);
}

int paint_board(vector<string>& s, int si, int sj) {
	int case1 = 0, case2 = 0;
	//case1: i+j가 짝수인게 W
	//case2: i+j가 홀수인게 B
	for (int i = 0; i < 8; i++) {
		//printf("%s", s[i]);
		for (int j = 0; j < 8; j++) {

			if ((i + j) % 2 == 0) {
				if (s[i+ si][j+ sj] != 'W') case1++;
				if (s[i + si][j + sj] != 'B') case2++;
			}
			else {
				if (s[i + si][j + sj] != 'B') case1++;
				if (s[i + si][j + sj] != 'W') case2++;
			}
		}
	}

	return min(case1, case2);
}