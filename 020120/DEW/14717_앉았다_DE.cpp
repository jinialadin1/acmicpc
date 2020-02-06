#include <stdio.h>
#include <vector>
using namespace std;
bool find_ans = false;
void sum_arr(int key, int sum, int depth);

int main()
{
	int tt[11], end[11];
	vector<int> card;
	int a, b;
	float ans;
	scanf("%d %d", &a, &b);

	for (int i = 1; i <= 10; i++) {
		tt[i] = 10 - i;
		card.push_back(i);
		if( i !=a && i !=b)
			card.push_back(i);
		end[i] = 0;
	}

	end[0] = 0;
	int v_size = card.size();
	for (int i = 0; i < v_size; i++) {
		for (int j = i+1; j < v_size; j++) {
			if (card[i] == card[j]) continue;
			end[(card[i]+ card[j])%10]= end[(card[i] + card[j]) % 10]+1;
		}
	}


	if (a == b) {
		ans = (float)(153-tt[a])/ (float)153;
	}
	else {
		int tmp = 0;
		for (int i = (a+b)%10 ; i <= 10; i++) {
			tmp += end[i];
		}
		ans = (float)(153 - tmp-8) / (float)153;
	}

	printf("%.3f",ans);
	return 0;
}