/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 예외처리
	try : 예외를 발견한다
	catch : 예외를 잡는다
	throw : 예외를 던진다

	try catch는 하나의 구문이므로 사이에 다른 코드를 넣으면
	컴파일 에러가 발생한다

	예외가 발생하지 않으면
	catch 블록은 건너뛴다

	예외가 발생하면
	예외 발생하면 나머지 try 구문은 실행되지 않고
	바로 catch 구문으로 간다

	C#에서 try - catch 구문
	python에서 try - exception 구문

	try 구문은 예외가 발생할만한 영역뿐만 아니라
	그와 관련된 모든 문장을 함께 묶어서 이를 하나의 일의 단위로 구성하는 것이다
*/

#include <iostream>
using namespace std;

int main(void)
{

	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;
	try {

		if (num2 == 0) {

			throw num2;
		}

		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;

	}
	catch (int ex) {	// ex에는 아무 변수명 지정 가능
						// throw 에서 던진 num2를 받아온다

		cout << "제수는 " << ex << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	
	cout << "end of main" << endl;
	return 0;
}