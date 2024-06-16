/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 예외의 전달
	try - catch 구문 없이 throw를 사용해서 예외가 발생하는 경우
	예외를 어떻게 처리하는지 보여주는 예제

	예외가 처리되지 않으면, 예외가 발생한 함수를 호출한 영역으로 예외 데이터와
	더불어 예외처리에 대한 책임까지 전달된다
*/

#include<iostream>
using namespace std;

void Divide(int num1, int num2) {

	if (num2 == 0) {

		throw num2;
	}

	cout << "나눗셈의 몫: " << num1 / num2 << endl;
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;
}

int main(void)
{

	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try {

		Divide(num1, num2);
		cout << "나눗셈을 마쳤습니다." << endl;
	}
	catch (int expn) {	// Divide에서 발생한 예외를 여기서 받는다.

		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}

	return 0;
}