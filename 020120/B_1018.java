import java.util.*;

public class B_1018{
	// B로 시작하는 것과 W로 시작하는 STRING 배열 만들어서 하나하나 비교하기? 
	public static String[] WB = {
			"WBWBWBWB", "BWBWBWBW", 
			"WBWBWBWB", "BWBWBWBW", 
            "WBWBWBWB", "BWBWBWBW", 
            "WBWBWBWB", "BWBWBWBW"
	};
	
	public static String[] BW = {
			"BWBWBWBW", "WBWBWBWB",
			"BWBWBWBW", "WBWBWBWB", 
			"BWBWBWBW", "WBWBWBWB", 
			"BWBWBWBW", "WBWBWBWB"
	}; 
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		String[] str = new String[m];
		
		// 큰수로 지정해서 비교
		int res = Integer.MAX_VALUE;
		
		for(int i = 0; i < m; i++) {
			str[i] = sc.next();
		}
		
		// 시작점을 기준으로 8X8로 자르고 
		for(int i = 0; i <= m - 8; i++) {
			for(int j = 0; j <= n - 8; j++) {
				// 아아아아 이거 몰라ㅏㅏㅏ
				// 함수로 넘길지 여기서 걍 무식하게 풀지 고민
				int resBW = 0;
				int resWB = 0;
				// BW
				for(int k = 0; k < 8; k++) {
					// 가로로 8번 자르기
					String temp = str[i + k].substring(j, j + 8);
					
					// 비교하기 이 부분 좀 간단하게 안되나 변수 두개 넘 불편
					for(int l = 0; l < 8; l++) {
						if(temp.charAt(l) == BW[k].charAt(l)) {
							resBW++;
						}
						if(temp.charAt(l) == WB[k].charAt(l)) {
							resWB++;
						}
					}
				}
				int t = Math.min(resBW, resWB);
				res = res > t ? t : res;
			}
		}
		
		System.out.println(res);
	}
}
