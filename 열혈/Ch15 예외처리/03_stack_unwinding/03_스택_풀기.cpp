/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 스택 풀기
	예외가 처리되지 않아서, 함수를 호출한 영역으로 예외 데이터가 전달되는 현상을 가리켜
	스택 풀기라고 한다
*/

#include<iostream>
using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{


	// SimpleFuncOne > SimpleFuncTwo > SimpleFuncThree 순으로 함수 실행이되고
	// SimpleFuncThree에서 예외 발생 > SimpleFuncTwo > SimpleFuncOne > main 순으로 예외 데이터가 전달된다
	// 만약 메인에서 예외 처리를 하지 않는다면, terminate 함수가 호출되면서 프로그램이 종료된다
	try {

		SimpleFuncOne();
	}
	catch (int expn) {

		cout << "예외코드: " << expn << endl;
	}

	return 0;
}

void SimpleFuncOne(void) {

	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void) {

	cout << "SimpleFuncTwo(void)" << endl;
	SimpleFuncThree();
}

void SimpleFuncThree(void) {

	cout << "SimpleFuncThree(void)" << endl;
	throw - 1;
}