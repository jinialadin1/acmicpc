import java.util.*;
import java.io.*;

/** ���� 3015 : ���ƽý� �����
 *  1. �׷����� �׷����� ������׷��� ����ߴ�.
 *  2. ������׷��� �޸� �������� Ž���� �������� �ʰ� ���������θ� Ž���� �����ϴ�
 *  3. ���� �ڸ��� ���ʿ��� ���� ū �ٸ� �������� ��� ���ʿ������� Ž��?
 *  4. �̷� ������ ��ü �� ���°���
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
		if(right - left <= 0) { // ������ �ڿ� �ƹ��͵� ���� ��
			return 0;
		}
		if(right - left == 1) { // ������ �ڿ� �ϳ��ۿ� ���� ���
			return 1;
		}
		
		long mid = (left+right) / 2;
		long divideLeft = divide(left, mid - 1); // ����
		long divideRight = divide(mid, right); // ����
		
		// �� ������ ���� ���� MAX ã��
		// MAX ���� ��� Ž�� �ϸ鼭 MAX�� ������ �ٷ� ����
		// �ϳ��� ����?���� MAX�� �Ѿ�� ���� ���
		long midLeft = man[(int) (mid - 1)]; // ���� ������(�߰�)
		long midRight = man[(int)mid];  // ������ ������(�߰�)
		
		long maxLeft = midLeft;
		long maxRight = midRight;
		
		
		// ���ذ����� ū ����� ���� �迭 -> �̳���� �������� ����ġ�� 
		ArrayList<Long> sideLeft = new ArrayList<Long>();
		ArrayList<Long> sideRigt = new ArrayList<Long>();
		
		for(long i = mid - 1; i >= left; i--) { // ���� Ž��
			if(man[(int)i] >= maxLeft) {// max ������ ũ��
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
		
		long res = divideLeft + divideRight; // ����
		// count�� ��� �ؾ����� �𸣰ڴ�.
		// ���ʺ��� Ž���ϸ鼭 ���ذ����� ũ�ٰ� �Ǵܵ� ���� �����̵忡 ����ġ�� ī��Ʈ�Ǵ°ǰ�?
		// �׷��� �������� �Ǵ� ���� ���?
		
		
		return res;
	}
}
