/*
날짜 : 2024. 6. 16
이름 : 배성훈
내용 : 지역변수 선언
	교재 p19 ~ 20

	C언어로 프로그램을 작성하는 경우에는 함수를 정의함에 있어서 
	지역변수의 선언이 항상 제일 먼저 등장해야만 했다

	그러나 C++의 지역변수 선언은 함수 내 어디든 삽입이 가능하다
	C언어의 새로운 표준에서는 C++과 마찬가지로 변수선언의 위치에 제한을 두지 않는다
	그러나 몇몇 컴파일러는 이를 허용하지 않는다

	아래 예제를 보면 한 번에 2개의 변수를 입력받고 있다
	첫 번째 정수와 두 번째 정수의 경계는 
	탭, 스페이스바, Enter 키의 입력과 같은 공백에 의해 나눠진다
*/

#include <iostream>

int main(void)
{

	int val1, val2;
	int result = 0;

	std::cout << "두 개의 숫자 입력: ";
	std::cin >> val1 >> val2;

	if (val1 < val2)
	{

		for (int i = val1 + 1; i < val2; i++)
		{

			result += i;
		}
	}
	else 
	{

		for (int i = val2 + 1; i < val1; i++)
		{

			result += i;
		}
	}

	std::cout << "두 수 사이의 정수 합: " << result << std::endl;

	return 0;
}