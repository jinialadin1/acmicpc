import java.util.*;
import java.io.*;

/**
 *  무식하게 풀기
 *  Pair로 하나하나 해볼까(key-value로 되어있어서 객체)
 */

/*
public class Beack_2261 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		Coordinate[] c = new Coordinate[n]; // 배열
		
		long res = Long.MAX_VALUE; // 결과값 반환
		
		for(int i = 0; i < n; i++) { 
			StringTokenizer st = new StringTokenizer(br.readLine());
			c[i] = new Coordinate(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken())); // 객체 생성
			for(int j = i - 1; j >= 0; j--) {
				// (x2 - x1)^2 + (y2 - y1)^2
				res = Math.min(res, (long)(Math.pow(c[j].x - c[i].x, 2)) 
									+ (long)(Math.pow(c[j].y - c[i].y, 2))); 
			}
		}
		
		bw.write(res+""); // long -> String으로 바꾸기 젤 편한 방식 ㅎㅋㅎㅎㅋㅎ
		bw.close();
		br.close();
	}
}
class Coordinate{
	long x, y;
	public Coordinate(long x, long y) {
		this.x = x;
		this.y = y;
	}
}*/