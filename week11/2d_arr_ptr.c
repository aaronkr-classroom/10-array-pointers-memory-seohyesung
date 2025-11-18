// 2d_arr_ptr.c
#include <stdio.h>

#define ROWS 3 // 2차원 배열의 행 개수
#define COLS 5 // 2차원 배열의 열 개수

// 2D 배열을 출력하는 함수
void printArr(char arr[ROWS][COLS]) {
	// printf("배열의 상태:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n"); // 각 행이 끝날 때 줄 바꿈
	}
	printf("\n"); // 종료
}

int main(void) {
	// ROWS x COLS 크기의 2D 배열 선언
	char data[ROWS][COLS] = { 0 }; // 모든 요소를 0으로 초기화
	char (*p)[COLS]; // COL 개의 char* 포인터 배열 선언

	p = data; // 포인터 배열 p에 2D 배열 data의 주소 할당
	
	printf("시작 전: \n");
	printArr(data); // 초기 상태 출력
	printf("press any key to continue...\n");
	getchar();


	// 포인터 p를 사용하여 2D 배열의 각 요소에 값 할당
	(*p)[1] = 3; // 첫 번째 행, 두 번째 열에 3 할당
	(*(p + 1))[2] = 4; // 두 번째 행, 세 번째 열에 4 할당
	(*(p + 2))[4] = 5; // 세 번째 행, 다섯 번째 열에 5 할당

	printf("초기 배열의 상태: \n");
	printArr(data);
	printf("press any key to continue...\n");
	getchar();

	// 2D 배열을 수정하기
	p = data; // 포인터 p를 다시 첫번째 행으로 초기화
	p++; // 포인터 p를 두 번째 행으로 이동
	(*p)[0] = 7; // 두 번째 행, 첫 번째 열에 7 할당
	(*p)[4] = 8; // 두 번째 행, 다섯 번째 열에 8 할당
	(*(p - 1))[3] = 9; // 첫 번째 행, 네 번째 열에 9 할당

	printf("두번째 수정 후 배열의 상태: \n");
	printArr(data);
	printf("press any key to continue...\n");
	getchar();

	// 포인터 산술 연산을 사용함
	char* ptr = &data[0][0]; // 2D 배열의 첫 번째 요소를 가르키는 포인터
	*(ptr + 6) = 10; // 7번째 요소에 10 할당 (두 번째 행, 두 번째 열)
	*(ptr + 10) = 11; // 11번째 요소에 11 할당 (세 번째 행, 첫 번째 열)
	*(ptr + 14) = 28; // 15번째 요소에 28 할당 (세 번째 행, 다섯 번째 열)
	// *(ptr + 15) = 100; // 오류 : 배열 범위 초과 접근, 배열 끝으로 넘어감
	// ptr의 길이가 ROWS * COLS 까지라서
	// ptr의 인덱스가 ROWS * COLS - 1 까지 접근 가능 (0부터 시작하므로)

	printf("포인터 산술 연산 후 배열의 상태: \n");
	printArr(data);
	printf("press any key to continue...\n");
	getchar();

	// 첫번째와 세번째 행을 바꾸기
	char temp[COLS]; // 임시 배열 선언
	for (int i = 0; i < COLS; i++) {
		temp[i] = data[0][i]; // 첫 번째 행을 temp에 복사
		data[0][i] = data[2][i]; // 세 번째 행을 첫 번째 행으로 복사
		data[2][i] = temp[i]; // temp를 세 번째 행으로 복사
	}

	printf("첫번째 행과 세번째 행 교환 후 배열의 상태: \n");
	printArr(data);
	printf("press any key to continue...\n");
	getchar();

	return 0;
}