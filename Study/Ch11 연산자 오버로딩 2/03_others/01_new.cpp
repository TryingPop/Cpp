/*
날짜 : 2023. 2. 16
이름 : 배성훈
내용 : new 연산자
	new 연산자가 하는 일
		1. 메모리 공간의 할당
		2. 생성자의 호출
		3. 할당하고자 하는 자료형에 맞게 반환된 주소 값의 형 변환

	이 중 객체의 생성과정은 다소 복잡한 과정을 거치므로
	생성자의 호출과 반환된 주소 값의 형 변환은 컴파일러가 책임진다
	그래서 실질적으로 new 연산자를 오버로딩 할 때에는 메모리 공간의 할당만 오버로딩 가능
	
	new 연산자를 오버로딩하려면 다음과 같은 형태로 해야한다
		void* operator new(size_t size) { ... }

	size_t는 일반적으로 다음과 같이 정의되어있다
	typedef unsigned int size_t;로 정의되어져 있다
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(0), ypos(0) { }

	// 크기의 정보는 바이트 단위
	void* operator new(size_t size) {

		cout << "operator new : " << size << endl;
		void* adr = new char[size];	// char의 크기가 1이라 char 단위로 메모리 공간을 할당해 반환
		// void* adr = malloc(size);
		return adr;
	}
};

int main(void)
{

	Point* pt = new Point(4, 5);
	return 0;
}