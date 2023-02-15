/*
날짜 : 2023. 2. 16
이름 : 배성훈
내용 : new와 delete 연산자
	delete 키워드를 이용하면
	컴파일러는 ptr이 가리키는 소멸자 먼저 호출
	그리고 다음의 형태로 정의된 함수에 ptr에 저장된 주소 값을 전달
		void operator delete(void* adr) { ... }
	
	일반적으로
		void operator delete (void* adr) {
			delete[] adr;
		}

	만약 컴파일러에서 void 포인터 형 대상의 delete 연산을 허용하지 않는다면,
		delete[] ((char*)adr);
	로 작성해 진행하면 된다

	이제 new와 delete 연산자를 오버로딩한 예제를 해보자

	예제에서 보듯이 operator new 와 operator delete 는 static 함수로 간주된다
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new(size_t size) {

		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete(void* adr) {

		cout << "operator delete()" << endl;
		delete[] adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{

	// 생성 전에 operator new를 호출
	Point* ptr = new Point(3, 4);	// operator new : 8
	cout << *ptr;	// [3, 4]
	delete ptr;		// operator delete()
	return 0;
}