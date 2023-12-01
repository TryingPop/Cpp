/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : if문을 이용한 예외처리
	if문을 이용해 예외상황의 발생유무를 확인한 다음에 그에 따른 처리를 진행하는 예제

	예외처릴 위한 코드와 프로그램의 흐름을 구성하는 코드를 쉽게 구분하지 못한다
	주석을 처리해 알릴 수 있으나 다른 정보의 기록에도 주석을 사용하기 때문에
	한 눈에 예외처리 구문임을 알아보기는 힘들다
*/

#include<iostream>
using namespace std;

int main(void)
{

	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;
	
	if (num2 == 0) {

		cout << "제수는 0이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	else {

		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	return 0;
}