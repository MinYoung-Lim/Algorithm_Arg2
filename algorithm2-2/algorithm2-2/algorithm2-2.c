#include <stdio.h>

int main() {

	int B[5][5] = { 0 };  //�迭 A �ʱ�ȭ
	int V = 1;  //1~25 ���� ����
	int R = 0;  //��
	int SW = 1;  //����ġ ����
	int CL = 0;  
	int CR = 0;
	int C = 0;  //��

	B[0][0] = V;  //A[0][0]�� 1�� ����
	V++;

	for (int i = 1; i < 5; i++) {            //�밢�� 4�� ����
		if (SW == 1) {   // ���� ������ ��
			R = i; CL = 0; CR = i;
			for (C = CL; C < CR + 1; C++) {
				B[R][C] = V;
				V++;
				R = R - SW;  //�� �� ����
			}
		}
		else {  //���� ������ ��
			R = 0; CL = i; CR = 0;
			for (C = CL; C > CR-1; C--) {
				B[R][C] = V;
				V++;
				R = R - SW;  //�� �� ����
			}
		}

		SW = -1 * SW;  //����ġ ���� �� ����
	}

	for (int i = 5; i < 8; i++) {         //�밢�� 3�� ����
		if (SW == 1) {  //���� ������ ��
			R = 4; CL = i - 4; CR = 4;
			for (C = CL; C < CR + 1; C = C + SW) {
				B[R][C] = V;
				V++;
				R = R - SW;  //�� �� ����
			}
		}
		else {  //���� ������ ��
			R = i - 4; CL = 4; CR = i - 4;
			for (C = CL; C > CR -1; C = C + SW) {
				B[R][C] = V;
				V++;
				R = R - SW;  //�� �� ����
			}
		}

		SW = -SW;  //����ġ���� �� ����
	}

	B[4][4] = V;  //������ 25 �־��ֱ�

	for (int i = 0; i<5; i++) {  // �迭 ���
		for (int j = 0; j< 5; j++) {
			printf("%d\t", B[i][j]);
		}
		printf("\n\n");
	}

}