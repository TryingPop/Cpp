/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 22p 문제1
	사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해보자.
	단 프로그램의 실행은 다음과 같이 이루어져야 한다.
	실행의 예
	1번째 정수 입력 : 1
	2번째 성수 입력 : 2
	3번째 성수 입력 : 3
	4번째 성수 입력 : 4
	5번째 성수 입력 : 5
	합계 : 15
*/

#include <iostream>

int main(void) 
{

	int num = 0;
	int input;

	// 풀이에서는 for 문 이용
	for (int i = 0; i < 5; i++) {

		std::cout << i + 1 << "번째 정수 입력: ";
		std::cin >> input;
		num += input;
	}

	std::cout << "합계: " << num << std::endl;
	return 0;
}