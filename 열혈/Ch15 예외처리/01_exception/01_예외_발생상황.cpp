/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 예외 발생상황
	예외는 문법적 오류가 아닌 프로그램의 논리에 맞지 않는 상황을 의미한다
*/

#include<iostream>
using namespace std;

int main(void)
{

	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;								// 7, 2를 입력하는 경우
														// 2, 0을 입력하는 경우
														// 더 이상 실행되지 않고 프로그램 종료

	cout << "나눗셈의 몫: " << num1 / num2 << endl;		// 3
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;	// 1
	return 0;
}