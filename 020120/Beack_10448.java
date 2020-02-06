import java.util.*;

public class Beack_10448{
	// 이건 어떻게 처리해야할지 모르겠다
	// 삼각수의 합 Tn에 대해서 n * (n + 1) / 2인데 자연수는 3~1000까지
	// 이 기준이 되는 자연수는 n일까 결과값일까 
	// 검색해보니까 결과값이다(n인줄 머쓱 졸려)
	// 계산을 해보면 n * (n + 1) / 2 < 1000 이라면 n은 44까지임
	// 1부터 44까지 해당 식에 맞는 데이터를 넣어주고
	// 완전 탐색으로 그 값에 해당되는 것이 있으면 true 없으면 false인데
	// 그 값에 해당된다는 조건문만 찾으면 될 것 같다
	// 근데 모르겠다.
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[] memo = new int [46];
		boolean[] res = new boolean[n + 1];

		
		// 해당되는 값 저장
		for(int i = 1; i <= 45; i++) {
			memo[i] = (i * (i + 1)) / 2;
		}
		
		// 조건문 뭐시기여
		// 아 아 아 아 맞아 완전 탐색이니까
		// 1 ~ 45까지 해당되는 값끼리 더해주고 그게 i값이 맞는지 확인하면 되는거 아녀
		// 첫 번째 넘이랑 두 번쨰 넘 1로 픽스하고 3번째넘 1~45까지 다 탐색해서 되는지 찾으면 되는거 아닌감
		for(int i = 0; i < n; i++) {
			int k = sc.nextInt();
			for(int j = 1; j <= 45; j++) {
				for(int l = 1; l <= 45; l++) {
					for(int m = 1; m <= 45; m++) {
						if(memo[j] + memo[l] + memo[m] == k) {
							res[i] = true;
						}
					}
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			if(res[i]) {
				System.out.println(1);
			}else {
				System.out.println(0);
			}
		}
	}
}
