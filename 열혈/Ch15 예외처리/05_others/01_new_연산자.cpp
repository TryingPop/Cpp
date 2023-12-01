/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : new 연산자
	new 연산에 의한 메모리 공간 할당이 실패하면 bad_alloc 이라는 예외가 발생
	bad_alloc은 헤더파일 new에 선언된 예외 클래스로서 메모리 공간의 할당이 실패했음을 알리는 의도로 정의

	이와 관련된 예제를 보자
*/

#include <iostream>
#include <new>
using namespace std;

int main(void)
{

	int num = 0;

	try {

		while (1) {

			num++;
			cout << num << "번째 할당 시도" << endl;	// 1
			new int[1000000][1000000];					// 바로 예외 발생
		}
	}
	catch (bad_alloc& bad) {

		cout << bad.what() << endl;						// bad allocation
		cout << "더 이상 할당 불가!" << endl;			// 출력
	}
}