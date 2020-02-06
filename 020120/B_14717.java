import java.util.*;

public class B_14717{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 이길 확률을 받아오는거
		// 떙과 끗을 어떻게 구분할까
		
		// 어차피 숫자는 1부터 10까지
		// 끗이 되는 경우?를 선택해보자...?
		int n = sc.nextInt();
		int m = sc.nextInt();
		int res = 0;
		
		if(n == m) {
			res = n;
		}
		
		// 땡이 아니라면 탐색을 통해 res의 위치가 어딘지 찾고
		// 완전 탐색을 통해 상대편이 나올 수 있는 모든 경우의 수
		// res보다 작은 숫자가 나오는 경우의 수
		// 모든 경우의수와 작은 숫자가 나올 경우의 수를 통해서 확률 구하기
		
		// 9 끗 : 1 + 8 / 8 + 1 / 2 + 7 / 7 + 2...
		// 경우의 수를 어떻게 구하는지?가 관건..
	}
}
