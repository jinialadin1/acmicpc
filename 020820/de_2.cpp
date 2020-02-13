#include <stdio.h>
#include <math.h>
using namespace std;
void move(int a, int b, int size);

int main() {
	int n, tot;
	scanf("%d",&n);
	tot = (int)pow(2, n);
	printf("%d\n", tot -1);
	move(1, 3, n);
	return 0;
}

void move(int a, int b, int size) {
	int c=-1;
	if (size == 1) {
		printf("%d %d\n",a,b);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (i != a && i != b) {
			c = i;
			break;
		}
	}

	move(a, c, size - 1);
	printf("%d %d\n", a, b);
	move(c, b ,size - 1);
}