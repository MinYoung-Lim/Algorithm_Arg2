#include <stdio.h>

int main() {

	int B[5][5] = { 0 };  //배열 A 초기화
	int V = 1;  //1~25 담을 변수
	int R = 0;  //행
	int SW = 1;  //스위치 변수
	int CL = 0;  
	int CR = 0;
	int C = 0;  //열

	B[0][0] = V;  //A[0][0]을 1로 설정
	V++;

	for (int i = 1; i < 5; i++) {            //대각선 4개 설정
		if (SW == 1) {   // 열이 증가할 때
			R = i; CL = 0; CR = i;
			for (C = CL; C < CR + 1; C++) {
				B[R][C] = V;
				V++;
				R = R - SW;  //행 값 갱신
			}
		}
		else {  //열이 감소할 때
			R = 0; CL = i; CR = 0;
			for (C = CL; C > CR-1; C--) {
				B[R][C] = V;
				V++;
				R = R - SW;  //행 값 갱신
			}
		}

		SW = -1 * SW;  //스위치 변수 값 변경
	}

	for (int i = 5; i < 8; i++) {         //대각선 3개 설정
		if (SW == 1) {  //열이 증가할 때
			R = 4; CL = i - 4; CR = 4;
			for (C = CL; C < CR + 1; C = C + SW) {
				B[R][C] = V;
				V++;
				R = R - SW;  //행 값 갱신
			}
		}
		else {  //열이 감소할 때
			R = i - 4; CL = 4; CR = i - 4;
			for (C = CL; C > CR -1; C = C + SW) {
				B[R][C] = V;
				V++;
				R = R - SW;  //행 값 갱신
			}
		}

		SW = -SW;  //스위치변수 값 변경
	}

	B[4][4] = V;  //마지막 25 넣어주기

	for (int i = 0; i<5; i++) {  // 배열 출력
		for (int j = 0; j< 5; j++) {
			printf("%d\t", B[i][j]);
		}
		printf("\n\n");
	}

}