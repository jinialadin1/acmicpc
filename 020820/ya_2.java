import java.util.*;

public class Main {
    /*
    기준이 3일떄
    기둥 1의 원반을 기둥 3으로 옮긴다.
    기둥 1의 원반을 기둥 2으로 옮긴다.
    기둥 3의 원반을 기둥 2으로 옮긴다.
    기둥 1의 원반을 기둥 3으로 옮긴다.
    기둥 2의 원반을 기둥 1으로 옮긴다.
    기둥 2의 원반을 기둥 3으로 옮긴다.
    기둥 1의 원반을 기둥 3으로 옮긴다.
    
    기둥 1에서 n - 1개의 원반을 기둥 2으로 옮긴다.
    기둥 1에서 1개의 원반을 기둥 3으로 옮긴다.
    기둥 2에서 n-1개의 원반을 기둥 3으로 옮긴다.
    반복
    */
    
	public static int count = 0;
	public static StringBuilder res = new StringBuilder();
	// 가장 큰 문제는 횟수를 어떻게 return 하느냐-
	// StringBuffer를 사용해서 insert도 쉽게, 사용되는 메모리량도 줄여보자!
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int k = sc.nextInt();
		
		hanoi(k, 1, 2, 3);
		
		res.insert(0, count + "\n");
		System.out.println(res);
		
	}
	
	public static void hanoi(int n, int from, int temp, int to){
		count++;
		if(n == 1){
			res.append(from + " " + to + "\n");
	    }else{
	    	hanoi(n-1, from, to, temp);
	    	res.append(from + " " + to + "\n");
	        hanoi(n-1, temp, from, to);
	    }
	}
}



