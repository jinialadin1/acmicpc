import java.util.*;

public class B_1051{
	
	// 졸려
	// M과 N이 있을 떄
	// 각 꼭짓점이 동일한 것 중 넓이가 가장 큰것을 찾는 문제
	// 어차피 범위도 좁으니 걍 무식하게 
	// 기준이 되는 길이?를 픽스하고 하나하나 다 비교해보자.
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int len = 0;
		int res = 1;
		
		String[] temp = new String [n+1];
		int[][] num = new int [n+1][m+1];
		
		// 입력받기
		/*
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				num[i][j] = sc.nextInt();
			}
		}*/
		for(int i = 0; i < n; i++) {
			temp[i] = sc.next();
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				num[i][j] = (temp[i].charAt(j));
			}
		}
		
		// 기준이 되는 길이 픽스하기
		if(n > m) { // 세로가 더 길면
			len = m;
		}else {
			len = n;
		}
		
		// for문 돌리기
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int k = 1; k < len; k++) {
					// 범위 내에 있고 각 꼭짓점들이 같은 숫자일때 결과값에 더해줌
					if(i + k < n && j + k < m &&
					   num[i + k][j] == num[i][j] &&
					   num[i + k][j + k] == num[i][j] &&
					   num[i][j + k] == num[i][j]) {
						res = Math.max(res, k + 1);
					}
				}
			}
		}
		
		System.out.println(res * res);
		
	}
}
