/*
날짜 : 2024. 6. 18
이름 : 배성훈
내용 : 참을 의미하는 true, 거짓을 의미하는 false
	교재p64 ~ 66

	bool 형은 C언어에는 존재하지 않고, C++에만 존재하는 자료형이었다
	그러나 C의 최근 표준에서는 bool을 기본자료형에 추가하였다

	하지만 bool은 C++의 기본자료형으로 인식을 많이 한다
	예전의 C 컴파일러가 bool을 지원하지 않기 때문이다

	C와 C++모두 정수 0은 거짓을 의미하는 숫자로,
	그리고 0이 아닌 모든 정수는 참을 의미하는 숫자로 정의하고 있다

	따라서 참과 거짓의 표현을 위해서 다음과 같이 상수를 정의하는 것이 보통이다

	#define TRUE 1
	#define FALSE 0

	이러한 참과 거짓의 표현방법은 C++에서도 여전히 사용된다
	그러나 C++에서는 참과 거짓의 표현을 위한 키워드 true, false를 정의하고 있기 때문에
	굳이 매크로 상수를 이용해서 참과 거짓을 표현할 필요가 없다

	true는 1이 아니고 false도 0이 아니다
	이 둘은 참과 거짓을 표현하기 위한 1바이트 크기의 데이터일 뿐이다
	true와 false가 정의되기 이전에는 참을 표현하기 위해서 숫자 1을,
	거짓을 표현하기 위해서 숫자 0을 사용했기 때문에, 이 둘을 출력하거나 정수의 형태로
	형 변환하는 경우에 각각 1과 0으로 변환하도록 정의되었을 뿐이다

	정수가 와야 하는 위치에 true와 false가 오는 경우 1과 0으로 형 변환이 일어난다
	숫자로 인식할게 아니라 참 거짓을 나타내는 데이터로 인식하는게 바람직하다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int num = 10;
	int i = 0;

	cout << "true: " << true << endl;
	cout << "false: " << false << endl;

	while (true)
	{

		cout << i++ << ' ';
		if (i > num) break;
	}

	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;			// 4
	cout << "sizeof 0: " << sizeof(0) << endl;			// 4
	cout << "sizeof true: " << sizeof(true) << endl;	// 1
	cout << "sizeof false: " << sizeof(false) << endl;	// 1

	return 0;
}