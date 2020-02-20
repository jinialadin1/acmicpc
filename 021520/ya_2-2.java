import java.util.*;
import java.io.*;

/* 히스토그램에서 가장 큰 직사각형의 넓이 구하기
 * 0을 입력 시 반복문 종료(인풋 고려하기, Line으로 구별하기)
 */

/*
public class B_6549 {
	public static long[] histo;
	public static void main(String[] args) throws IOException {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Scanner sc = new Scanner(System.in);
		//StringBuilder sb = new StringBuilder();
		
		while(true) {
			int n = sc.nextInt();
			if(n == 0) {
				return;
			}
			
			histo = new long[n];
			
			for(int i = 0; i < n; i++) {
				histo[i] = sc.nextLong();
			}
			
			// 분할 & 정복
			System.out.println(divide(0, n-1));
		}
	}
	
	public static long divide(int left, int right) {
		if(left == right) {
			return (int)histo[left]; // 히스토그램 그래프가 하나밖에 없는 경우
		}
		
	    int mid = (left + right) / 2;
	    long res = Math.max(divide(left, mid), divide(mid + 1, right));
	    int lo = mid, hi = mid + 1;
	    int height = Math.min((int)histo[lo], (int)histo[hi]);
	    res = Math.max(res, height * 2);

		// 최대 사각형 넓이 구하기
		while (left < lo || hi < right) {
	        if (hi < right && (lo == left || histo[lo - 1] < histo[hi + 1])) {
	            ++hi;
	            height = Math.min(height, (int)histo[hi]);
	        }
	        else {
	            --lo;
	            height = Math.min(height, (int)histo[lo]);
	        }
	        //확장한 후 사각형의 넓이
	        res = Math.max(res, height * (hi - lo + 1));
		}
		
		return res;
	}
}*/
