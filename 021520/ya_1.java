import java.util.*;
import java.io.*;

/**
 *  �����ϰ� Ǯ��
 *  Pair�� �ϳ��ϳ� �غ���(key-value�� �Ǿ��־ ��ü)
 */

/*
public class Beack_2261 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		Coordinate[] c = new Coordinate[n]; // �迭
		
		long res = Long.MAX_VALUE; // ����� ��ȯ
		
		for(int i = 0; i < n; i++) { 
			StringTokenizer st = new StringTokenizer(br.readLine());
			c[i] = new Coordinate(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken())); // ��ü ����
			for(int j = i - 1; j >= 0; j--) {
				// (x2 - x1)^2 + (y2 - y1)^2
				res = Math.min(res, (long)(Math.pow(c[j].x - c[i].x, 2)) 
									+ (long)(Math.pow(c[j].y - c[i].y, 2))); 
			}
		}
		
		bw.write(res+""); // long -> String���� �ٲٱ� �� ���� ��� ������������
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