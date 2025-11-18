// arr.ptr.c
#include <stdio.h>

#define SIZE 10

int main() {
	char data[SIZE] = {
		1,2,3,4,5,6,7,8,9,10
	};
	int result = 0, // 합산에 사용할 result 변수
		i;
	char* p = data; // data 배열의 시작 주소를 가리키는 포인터

	// 10번 반복하면서 포인터 p를 사용하여 
	// 배열 각 요소를 result에 합산
	for (i = 0; i < SIZE; i++) { // 9; data[9]까지 접근
		printf("지금 p = %p, result: %d\n",p , result); 
		// 포인터 p가 가리키는 배열 요소 값을 result에 합산
		result = result + *p;
		// data 배열의 다음 요소로 포인터 주소 이동
		p++; // 다음 배열 요소로 포인터 이동
	}

	printf("마지막 result: %d\n", result);
	
	return 0;
}