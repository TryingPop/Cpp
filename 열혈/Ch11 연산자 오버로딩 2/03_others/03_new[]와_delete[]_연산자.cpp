/*
날짜 : 2023. 2. 16
이름 : 배성훈
내용 : new[]와 delete[] 연산자
	new 연산자를 이용한 배열할당 시 호출되는 함수이다
	호출되는 함수는 다음과 같다
		void* operator new[](size_t size) { ... }

	delete[] 역시 배열소멸 시 호출되는 함수이다
	호출되는 함수는 다음과 같다
		void operator delete[](void* adr) { ... }

	아래는 예제이다	
*/

#include<iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) 
		: xpos(x), ypos(y) { }
	
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new (size_t size) {

		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void* operator new[](size_t size) {

		cout << "operator neww [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete (void* adr) {

		cout << "operator delete ()" << endl;
		delete[] adr;
	}

	void operator delete[](void* adr) {

		cout << "operator delete[] ()" << endl;
		delete[] adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
}

int main(void)
{

	Point* ptr = new Point(3, 4);	// operator new : 8
	Point* arr = new Point[3];		// operator new[] : 24
	
	delete ptr;						// operator delete ()
	delete[] arr;					// operator delete[] ()
	return 0;
}