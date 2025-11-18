// rubiks_cube.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 3 // 길이
#define FACES 6 // 면

// 전역 변수 선언함
char* colors[FACES] = {
	"white", "red", "blue", "green", "orange", "yellow"
};
char letters[FACES] = { 'W','R','B','G','O','Y' };
int hexColors[FACES] = {
	0xFFF, 0xF00, 0x00F, 0x0F0, 0xFA0, 0xFF0
};

// 3x3x6 배열로 큐브 상태 정의 (6개의 면)
int cube[LENGTH][LENGTH][FACES];

// 출력 모드 선택
enum PrintMode { STRING, LETTER, HEX };

// 큐브 초기화 함수
void initCube() {
	for (int i = 0; i < FACES; i++) {
		for (int j = 0; j < LENGTH; j++) {
			for (int k = 0; k < LENGTH; k++)
				cube[i][j][k] = i;
		}
	}
}

// 큐브 출력 함수
void printCube(enum PrintMode mode){
	const char* labels[FACES] = {
		"Up", "Left","Front","Right","Back","Down"
	};
	for (int i = 0; i < FACES; i++) {
		printf("%s face:\n", labels[i]);
		for (int j = 0; j < LENGTH; j++) {
			for (int k = 0; k < LENGTH; k++) {
				switch (mode) {
				case STRING:
					printf("%-7s ", colors[cube[i][j][k]]);
					break;
				case LETTER:
					printf("%c ", letters[cube[i][j][k]]);
					break;
				case HEX:
					printf("%#05x ", hexColors[cube[i][j][k]]); // 
					break;

				}
			}
			printf("\n"); // 다음행으로 가기
		}
		printf("\n"); // 다음 면으로 가기
	}
}

// 90도 시계 방향 회전
void rotateFace(int face) {

}

// 큐브 섞기 함수 (랜덤 회전)
void scrambleCube() {

}

// 오른쪽 회전
void rotateRight() { 
	int temp[LENGTH];
	// 오른쪽 면 시걔 방향 회전
	for (int i = 0; i < LENGTH; i++) temp[i] = cube[3][i][2];
	for (int i = 0; i < LENGTH; i++) cube[3][i][2] = cube[0][2][2 - i];
	for (int i = 0; i < LENGTH; i++) cube[0][2][2 - i] = cube[1][2 - i][0];
	for (int i = 0; i < LENGTH; i++) cube[1][2 - i][0] = cube[5][0][i]; //
	for (int i = 0; i < LENGTH; i++) cube[5][0][i] = temp[i];
}

// 쉽게 섞기 함수
void easyScramble() {
	printf("scrambling...\n");
	for (int i = 0; i < 3; i++) {
		rotateRight(); // 단순 예제 : 오른쪽 5회 회전
	}
}

int main(void) {
	// 초기화
	initCube();
	printf("Initial cube:\n");
	printCube(STRING); // 다른 모드를 선택

	printf("press any key to rotate:");
	getchar();

	rotateRight();
	printCube(STRING);

	printf("press any key to scramble:");
	getchar();

	// 섞기(mix)
	for (int i = 1; i <= 4; i++) {
		easyScramble();
		printCube(STRING);
	}

	return 0;
}