import java.io.*;
import java.util.*;

// 이전에 스캐너로 했다가 시간 잡아먹어서 귀찮아도 버퍼 써야 겠다.
// 프렉탈 삼각형 만드는 것 같다
// 쪼개보니 3, 6, 12일때 각각 프렉탈이 만들어지고 3번의 삼각형이 반복되는 경우
// 이것에 대한 분할 생각이 안난다.. 리컬시브 어캐함 
// 일단 무식하게 풀기로 해볼까 -> 안됨 답이 안나옴
// 6까지는 규칙이 되었는데 12부터는 규칙이 안된다
// 음 12이상부터는 두 개로 쪼개는게 더 나을것같다.
// 어차피 분할 정복이니 3인거 따로 6인거 따로 12인거 따로 생각하고
// 붙일때 12인 놈은 6두개 붙이고, 6은 3 두개인거 붙이기???
// ㄴㄴ 그렇다기 보단 기준이 되는 3개일 떄 그 다음 6이되면 이 3개를 아래에 양옆에 붙이고 또 늘어나면 이 전의 6개를 또 양옆에 붙이고 반복
// 그럼 식을 잘 세워야 할 텐데 중간을 기준으로 쪼개보자
// n은 3 * 2^k 만 가능, 프렉탈이 시작되는 x, y축을 찾아서
// 프렉탈 삼각형을 만들어주면 되지 않을까
// k의 최댓값은 10이면 N의 최댓값은 1024 * 3 = 3072, 가로는 2n-1
// 세로 최대는 3072가 나타나고 가로 최대는 6143
// 3제외 반복되는 프렉탈은 위쪽 1개  x, y부터 시작하는데 n / 2까지인 부분을 그려주고
// 3제외 프렉탈은 위쪽  1개 아랫쪽에 왼쪽 1개 오른쪽 1개 존재(3인경우 제외)
// ?? 시간초과요?? 에바...... 버퍼도 썼는데.... 메모리떄문인가... 동적으로 바꿔?
// 또 시간 초과 -> println도 버퍼사용해보기 그래도 안되면 자바는 답이 없다.

public class Main {
	
	//public static char[][] map = new char[3100][6200];
	public static char[][] map;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		
		map = new char[n][2 * n - 1];
		
		for(int i = 0; i < n; i++) {// 세로
			for(int j = 0; j < 2 * n - 1; j++) { //가로
				map[i][j] = ' '; // 공백으로 초기화
			}
		}
		
		// 별 그리기 함수 호출
		p_start(0, n - 1, n);
		
		for(int i = 0; i < n; i++) {
			bw.write(map[i]);
			bw.write('\n');
		}
		
		br.close();
		bw.flush();
	}
	
	public static void p_start(int i, int j, int n) {
		// 별 그리기
		if(n == 3) {
			map[i][j] = '*';
			
			map[i + 1][j - 1] = map[i + 1][j + 1] = '*';
			
            			map[i + 2][j - 2] = map[i + 2][j - 1] = map[i + 2][j] = map[i + 2][j + 1] = map[i + 2][j + 2] = '*';
            
            			return;
		}
		
		p_start(i, j, n / 2); // 반으로 쪼개서 위 삼각형 만들어주기
		p_start(i + n / 2, j - n / 2, n / 2);
		p_start(i + n / 2, j + n / 2, n / 2);
	}
}
