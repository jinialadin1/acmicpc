import java.util.*;
import java.io.*;

/** 시간 초과 문제 해결 흑흑이
 *  1. 스캐너 -> 키보드 버퍼
 *  2. 함수 호출할 때 마다 sorted 메모리 생성 -> 정적변수로 한번만 선언
 *  3. 데이터 범위 맞지 않아서 int -> long
 */

public class Main
{
	public static long count = 0;
	public static long sorted[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// String Type으로 받는 키보드 버퍼를 Int로 바꿔줌
		int k = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine());
		long[] arr = new long[k];
		sorted = new long[k];
		
		for(int i = 0; i < k; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		m_sort(arr, 0, k - 1);
		System.out.println(count);
	}
	
	public static void m_sort(long[] arr, int start, int end) {
		if(start < end) {
			int temp = (start + end) / 2;
			m_sort(arr, start, temp); // 앞 부분 분할 정복
			m_sort(arr, temp + 1, end); // 뒷 부분 분할 정복
			merge(arr, start, temp, end); // 부분집합 다루기
		}
	}
	
	public static void merge(long arr[], int start, int temp, int end) {
		int i = start;  // 첫 부분 집합 시작
		int j = temp + 1; // 두 번째 부분 집합 시작 위치
		int k = start; // 정렬된 배열 원소를 저장할 위치 k 
		
		if(start == end) {
			return;
		}
		
		while(i <= temp && j <= end) {
			if(arr[i] <= arr[j]) {
				// 후위 연산자 써서 깔끔하게 k, i, j 증가
				sorted[k++] = arr[i++];
			}else {
				sorted[k++] = arr[j++];
				// 왼쪽 배열에 남아있는 숫자만큼 스왑 발생
				count += temp + 1 - i;
			}
		}
		
		// 정렬 swap
		while(i <= temp) {
			sorted[k++] = arr[i++];
		}while(j <= end) {
			sorted[k++] = arr[j++];
		}
		
		for(int idx = start; idx <= end; idx++) {
			arr[idx] = sorted[idx];
		}
	}
}