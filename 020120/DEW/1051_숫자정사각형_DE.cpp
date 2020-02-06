#include <stdio.h>
#include <vector>
using namespace std;
bool find_ans = false;
void wider(int val, int si, int sj, int wide);
int max_val = 1;
int n, m;
int** arr;
int main() {
	scanf("%d %d",&n,&m);
	arr = new int*[n + 1]();

	for (int i = 0; i < n; i++) {
		arr[i] = new int [m + 1]();
		scanf("%c", &arr[i][0]);
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
			arr[i][j] -= 48;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			 wider(arr[i][j], i, j, 1);
		}
	}
	printf("%d", max_val* max_val);
	return 0;
}

void wider(int val, int si, int sj, int wide) {
	int cnt=0;
	if (si + wide-1 >= n || sj + wide-1 >= m) {
		return;
	}
		
	int dir_i[5] = { si, si + wide-1, si			, si + wide-1 };
	int dir_j[5] = { sj, sj		,	sj+ wide-1,  sj+ wide-1 };

	for (int d = 0; d < 4; d++) {
	//	printf("(%d,%d) ",dir_i[d], dir_j[d]);
		if (arr[dir_i[d]][dir_j[d]] == val) cnt++;
	}
	//printf("\n");
	if (cnt == 4 && wide > max_val  ) {
		max_val = wide;
	}
	return wider(val, si, sj, wide + 1);
}