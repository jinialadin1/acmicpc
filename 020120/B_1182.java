import java.util.*;

public class B_1182{
	
	static int res = 0;
	static int[] ns = new int[2];
	
	public static void main(String[] args) {
		Scanner	 sc = new Scanner(System.in);
		// 0 : N
		ns[0] = sc.nextInt();
		// 1 : S
		ns[1] = sc.nextInt();
		
		int[] num = new int[ns[0]+1];
		
		for(int i = 0; i < ns[0]; i++) {
			num[i] = sc.nextInt();
		}
		PSS(num, 0, 0);
		
		System.out.println(res);
	}
	
	public static void PSS(int[] num, int i, int sum) {
		int temp = sum + num[i];
		// 인덱스가 N보다 크거나 작으면 return
		// 해당된 값이 S와 동일하면 결과값 상승 
		if(i >= ns[0]) {
			return;
		}
		if(temp == ns[1]) {
			res++;
		}
		// 완전탐색
		// 1. 현재의 인덱스를 더해가며 부분수열 진행
		PSS(num, i+1, temp);
		
		// 2. 현재의 인덱스를 더하지 않고 그 다음부터 부분수열 진행
		PSS(num, i+1, sum);
	}
}
