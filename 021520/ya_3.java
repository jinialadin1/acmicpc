import java.util.*;
import java.io.*;

/* 3^7 = 2187, 3 <= input <= 2187
 * 그 책에 있는 것과 비슷한 코드
 * 첫 정사각형 탐색 -> 다른 숫자 존재 시 9분할 -> 사각형 탐색
 * 책 : 위치만 바꿔줘서 탐색, 그러나 이건 숫자가 3가지 경우
 */
/*
public class B_1780 {
	static int box[][] = new int[2188][2188];
	static int res[] = new int[3];
	
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		// 입력
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) {
				box[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		divide(n, 0, 0);
		bw.write(res[2]+"\n"); // -1
		bw.write(res[0]+"\n"); // 0
		bw.write(res[1]+"\n"); // 1
		bw.close();
		br.close();
	}
	
	public static void divide(int n, int h, int w) {
		// 해당되는 정 사각형이 전부 같은 값이 들어있는지 체크.
		if(isCheck(n, h, w)) {
			if(box[h][w] == -1) {
				res[2]++;
			}else {
				res[box[h][w]]++; 
			}
		}else { // 값이 같지 않으면 분할
			// 종이를 같은 크기의 9조각으로 자른다.
			// 3 * 3 -> 1 * 1, 9 * 9 -> 3 * 3
			// 27 * 27 -> 9 * 9, 즉 n * n -> (n / 3) * (n / 3)
			int temp = n / 3;
			for(int i = 0; i < 3; i++) { // 9조각이면 결국 가로 * 세로 = 3 * 3, 3번씩 반복
				for(int j = 0; j < 3; j++) {
					divide(temp, (h + temp * i), (w + temp * j));
				}
			}
		}
	}
	
	public static boolean isCheck(int n, int h, int w) {
		int start = box[h][w]; // 해당 되는 분할의 시작점
		
		for(int i = h; i < h + n; i++) { // h + n 하는 이유는 시작점~분할되는 정사각형
			for(int j = w; j < w + n; j++) {
				if(start != box[i][j]) { // 시작점과 분할된 사각형에 있는 데이터가 맞지 않으면 바로 false
					return false;
				}
			}
		}
		
		return true;
	}
}*/
