/*
날짜 : 2023. 1. 26
이름 : 배성훈
내용 : 교재 135p 문제2
	문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하자.
	이 클래스의 두 가지 기능은 다음과 같다
		- 문자열 저장
		- 문자열 출력

	아래의 main 함수와 실행의 예에 부합하는 Printer 클래스를 정의하되,
	이번에도 역시 멤버변수는 private으로, 멤버함수는 public으로 선언하자.
	int main(void)
	{
		Printer pnt;
		pnt.SetString("Hello world!");
		pnt.ShowString();

		pnt.SetString("I love C++");
		pnt.ShowString();
		return 0;
	}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// malloc을 이용해 정의해보자
class Printer {

private:
	// char* savedStr;
	char savedStr[20];

public:
	void SetString(const char* inputStr) {
		/*
		// 해제하는 코드를 만들어야 하는데 모르겠다
		savedStr = (char*)malloc(sizeof(inputStr));
		strcpy(savedStr, inputStr);
		*/
		
		strcpy(savedStr, inputStr);
	};

	void ShowString() {

		cout << savedStr << endl;
		// free(savedStr);
	};
};

int main(void) 
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}