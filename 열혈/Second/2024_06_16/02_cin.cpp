/*
날짜 : 2024. 6. 16
이름 : 배성훈
내용 : scanf를 대신하는 데이터의 입력
	교재 p17 ~ 19

	아래 예제를 보면 
	키보드로부터의 데이터 입력에도 헤더파일 선언문
	#include <iostream>이 필요하다

	그리고 키보드로부터의 데이터 입력에는
	std::cin과 >> 연산자가 사용된다

	변수의 선언은 어디서든 가능하다

	데이터 입력을 위해서는
	std::cin >> (변수);
	형태면 된다

	C++에서는 데이터의 입력도 데이터의 출력과 마찬가지로 별도의 포맷 지정이
	필요 없기 때문이다

	아래 예제를 val1, val2, result를 double로 바꿔서 실수 값을 넣어도
	잘 작동한다
*/

#include <iostream>

int main(void)
{

	int val1;
	std::cout << "첫 번째 숫자 입력: ";
	std::cin >> val1;

	int val2;
	std::cout << "두 번째 숫자 입력: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈결과: " << result << std::endl;

	return 0;
}