/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 교재 552p 문제1
	만약에 Chapter 11을 공부하면서 스마트 포인터도 공부를 했다면,
	이 문제를 반드시 해결하고 넘어가기 바란다.
	자! 그럼 문제를 제시하겠다.
	우리는 앞서 Chapter 11에서 다음의 형태로 스마트 포인터를 정의하였다.

	class SmartPtr {

	private:
		Point* posptr;
		
	public:
		SmartPtr(Point* ptr)
			: posptr(ptr) { }

		Point& operator*() const {
			return *posptr;
		}

		Point* operator->() const {
			return posptr;
		}

		~SmartPtr() {
			delete posptr;
		}
	};

	이 스마트 포인터를 템플릿으로 정의하여, 어떠한 클래스의 객체도 참조할 수 있는 포인터가 되게하자.
	그리고는 아래의 Point 클래스와 main 함수를 기반으로 예제를 완성해보자.
	참고로 스마트 포인터는 이렇듯 템플릿의 형태로 정의가 된다.

	class Point {

	private:
		int xpos, ypos;

	public:
		Point(int x = 0, int y = 0)
			: xpos(x), ypos(y) { }

		void SetPos(int x, int y) {
			xpos = x;
			ypos = y;
		}

		void ShowPosition() const {
			cout << '[' << xpos << ", " << ypos << ']' << endl;
		}
	};

	int main(void)
	{

		SmartPtr<Point> sptr1(new Point(1, 2));
		SmartPtr<Point> sptr2(new Point(3, 4));
		sptr1->ShowPosition();
		sptr2->ShowPosition();
		sptr1->SetPos(10, 20);
		sptr2->SetPos(30, 40);
		sptr1->ShowPosition();
		sptr2->ShowPosition();
		return 0;
	}
*/

#include <iostream>
using namespace std;

template <class T>
class SmartPtr {

private:
	T* ptr;

public:
	SmartPtr(T* ptr)
		: ptr(ptr) { }

	T& operator*() const {

		return *ptr;
	}

	T* operator->() const {

		return ptr;
	}

	~SmartPtr() {

		delete ptr;
	}
};

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	void SetPos(int x, int y) {

		xpos = x;
		ypos = y;
	}

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void) 
{

	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();	// [1, 2]
	sptr2->ShowPosition();	// [3, 4]
	sptr1->SetPos(10, 20);	
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();	// [10, 20]
	sptr2->ShowPosition();	// [30, 40]
	return 0;
}