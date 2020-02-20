import java.util.*;
import java.io.*;

/* ������׷����� ���� ū ���簢���� ���� ���ϱ�
 * 0�� �Է� �� �ݺ��� ����(��ǲ ����ϱ�, Line���� �����ϱ�)
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
			
			// ���� & ����
			System.out.println(divide(0, n-1));
		}
	}
	
	public static long divide(int left, int right) {
		if(left == right) {
			return (int)histo[left]; // ������׷� �׷����� �ϳ��ۿ� ���� ���
		}
		
	    int mid = (left + right) / 2;
	    long res = Math.max(divide(left, mid), divide(mid + 1, right));
	    int lo = mid, hi = mid + 1;
	    int height = Math.min((int)histo[lo], (int)histo[hi]);
	    res = Math.max(res, height * 2);

		// �ִ� �簢�� ���� ���ϱ�
		while (left < lo || hi < right) {
	        if (hi < right && (lo == left || histo[lo - 1] < histo[hi + 1])) {
	            ++hi;
	            height = Math.min(height, (int)histo[hi]);
	        }
	        else {
	            --lo;
	            height = Math.min(height, (int)histo[lo]);
	        }
	        //Ȯ���� �� �簢���� ����
	        res = Math.max(res, height * (hi - lo + 1));
		}
		
		return res;
	}
}*/
