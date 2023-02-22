/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ���� 552p ����1
	���࿡ Chapter 11�� �����ϸ鼭 ����Ʈ �����͵� ���θ� �ߴٸ�,
	�� ������ �ݵ�� �ذ��ϰ� �Ѿ�� �ٶ���.
	��! �׷� ������ �����ϰڴ�.
	�츮�� �ռ� Chapter 11���� ������ ���·� ����Ʈ �����͸� �����Ͽ���.

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

	�� ����Ʈ �����͸� ���ø����� �����Ͽ�, ��� Ŭ������ ��ü�� ������ �� �ִ� �����Ͱ� �ǰ�����.
	�׸���� �Ʒ��� Point Ŭ������ main �Լ��� ������� ������ �ϼ��غ���.
	����� ����Ʈ �����ʹ� �̷��� ���ø��� ���·� ���ǰ� �ȴ�.

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