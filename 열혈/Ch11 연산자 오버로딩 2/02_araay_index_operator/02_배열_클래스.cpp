/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 배열 클래스
	경계검사를 하는 배열 클래스를 만들어보자
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {

private:
	int* arr;
	int arrlen;

public:
	BoundCheckIntArray(int len)
		: arrlen(len) {

		arr = new int[len];
	}

	int& operator[](int idx) {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	~BoundCheckIntArray() {

		delete[] arr;
	}
};

int main(void)
{

	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++) {

		arr[i] = (i + 1) * 11;
	}

	for (int i = 0; i < 6; i++) {

		cout << arr[i] << endl;	// i = 6일 때 
								// Array index out of bound exception 구문 뜬다
	}

	BoundCheckIntArray cpy1(5);

	// 안전하지 않은 코드들
	cpy1 = arr;						// 이전 배열에 접근 못해서 메모리 누수 + 얕은 복사
	BoundCheckIntArray copy = arr;	// 얕은 복사 문제
	// 대입 연산자와 복사생성자를 private 선언해서 막을 수 있다
	// 그러나 배열은 유일성이 보장되어야 하기 때문에 대부분의 경우 저장소의 복사는 불필요하다
}