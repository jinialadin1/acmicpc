import java.util.*;
import java.io.*;

/* 3^7 = 2187, 3 <= input <= 2187
 * �� å�� �ִ� �Ͱ� ����� �ڵ�
 * ù ���簢�� Ž�� -> �ٸ� ���� ���� �� 9���� -> �簢�� Ž��
 * å : ��ġ�� �ٲ��༭ Ž��, �׷��� �̰� ���ڰ� 3���� ���
 */
/*
public class B_1780 {
	static int box[][] = new int[2188][2188];
	static int res[] = new int[3];
	
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		// �Է�
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
		// �ش�Ǵ� �� �簢���� ���� ���� ���� ����ִ��� üũ.
		if(isCheck(n, h, w)) {
			if(box[h][w] == -1) {
				res[2]++;
			}else {
				res[box[h][w]]++; 
			}
		}else { // ���� ���� ������ ����
			// ���̸� ���� ũ���� 9�������� �ڸ���.
			// 3 * 3 -> 1 * 1, 9 * 9 -> 3 * 3
			// 27 * 27 -> 9 * 9, �� n * n -> (n / 3) * (n / 3)
			int temp = n / 3;
			for(int i = 0; i < 3; i++) { // 9�����̸� �ᱹ ���� * ���� = 3 * 3, 3���� �ݺ�
				for(int j = 0; j < 3; j++) {
					divide(temp, (h + temp * i), (w + temp * j));
				}
			}
		}
	}
	
	public static boolean isCheck(int n, int h, int w) {
		int start = box[h][w]; // �ش� �Ǵ� ������ ������
		
		for(int i = h; i < h + n; i++) { // h + n �ϴ� ������ ������~���ҵǴ� ���簢��
			for(int j = w; j < w + n; j++) {
				if(start != box[i][j]) { // �������� ���ҵ� �簢���� �ִ� �����Ͱ� ���� ������ �ٷ� false
					return false;
				}
			}
		}
		
		return true;
	}
}*/
