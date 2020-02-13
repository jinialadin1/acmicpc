#include <stdio.h>
#include <vector>
using namespace std;
void draw_triangle(int size, int si, int sj);
char** pic;

int main() {
	int k;
	scanf("%d",&k);
	pic = new char*[2*k + 2]();
	for (int i = 0; i < k; i++) {
		pic[i]  = new char [2*k + 2]();
	}

	draw_triangle(k,0,k);

	for (int i = 0; i <k; i++) {
		for (int j = 1; j <= 2*k; j++) {
			if(pic[i][j]=='*')
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

void draw_triangle(int size, int si, int sj) {
	if (size == 3) {
		pic[si][sj] = '*';
		pic[si+1][sj-1] = '*'; pic[si + 1][sj + 1] = '*';
		for (int j = 0; j < 5; j++) {
			pic[si + 2][sj - 2 + j] = '*';
		}
		return;
	}

	draw_triangle(size / 2, si, sj);
	draw_triangle(size / 2, si+ size / 2, sj- size / 2);
	draw_triangle(size / 2, si + size / 2, sj + size / 2);
}