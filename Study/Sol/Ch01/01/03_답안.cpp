/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 57p 문제3
	숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자.
	예를들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야 한다.
*/

#include <iostream>

int main(void)
{

	int num;
	std::cout << "구구단 정보 입력: ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++) {

		std::cout << num << 'x' << i << '=' << num * i << std::endl;
	}

	return 0;
}