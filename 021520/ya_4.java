import java.util.*;
import java.io.*;

/** 백준 3015 : 오아시스 재결합
 *  1. 그래프로 그려보니 히스토그램과 비슷했다.
 *  2. 히스토그램과 달리 양쪽으로 탐색이 가능하지 않고 오른쪽으로만 탐색이 가능하다
 *  3. 절반 자르고 양쪽에서 가장 큰 바를 기준으로 삼고 왼쪽에서부터 탐색?
 *  4. 이런 생각이 대체 왜 나는거지
 */

public class B_3015 {
	public static long[] man = new long[500000];
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		
		long n = Long.parseLong(br.readLine());
		
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			man[i] = Long.parseLong(st.nextToken());
		}
		
		long res = divide(0, n-1);
		
		bw.write(res+"");
		bw.close();
		br.close();
	}
	
	public static long divide(long left, long right) {
		if(right - left <= 0) { // 기준점 뒤에 아무것도 없을 시
			return 0;
		}
		if(right - left == 1) { // 기준점 뒤에 하나밖에 없을 경우
			return 1;
		}
		
		long mid = (left+right) / 2;
		long divideLeft = divide(left, mid - 1); // 분할
		long divideRight = divide(mid, right); // 분할
		
		// 양 옆에서 높은 층과 MAX 찾기
		// MAX 같은 경우 탐색 하면서 MAX에 닿으면 바로 ㅂㅂ
		// 하나의 공간?에서 MAX를 넘어가는 경우는 없어서
		long midLeft = man[(int) (mid - 1)]; // 왼쪽 시작점(중간)
		long midRight = man[(int)mid];  // 오른쪽 시작점(중간)
		
		long maxLeft = midLeft;
		long maxRight = midRight;
		
		
		// 기준값보다 큰 놈들을 담을 배열 -> 이놈들을 기준으로 가지치기 
		ArrayList<Long> sideLeft = new ArrayList<Long>();
		ArrayList<Long> sideRigt = new ArrayList<Long>();
		
		for(long i = mid - 1; i >= left; i--) { // 왼쪽 탐색
			if(man[(int)i] >= maxLeft) {// max 값보다 크면
				sideLeft.add(man[(int)i]); 
				maxLeft = man[(int)i];
			}
		}
		
		for(long i = mid; i < right; i++) {
			if(man[(int)i] > maxRight) {
				sideRigt.add(man[(int)i]);
				maxRight = man[(int)i];
			}
		}
		
		long res = divideLeft + divideRight; // 정복
		// count를 어떻게 해야할지 모르겠다.
		// 왼쪽부터 탐색하면서 기준값보다 크다고 판단된 왼쪽 슬라이드에 마주치면 카운트되는건가?
		// 그러면 기준점이 되는 놈은 어떻게?
		
		
		return res;
	}
}
