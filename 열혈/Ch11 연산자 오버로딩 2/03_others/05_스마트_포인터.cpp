/*
��¥ : 2023. 2. 16
�̸� : �輺��
���� : ����Ʈ ������
	����Ʈ �����ʹ� ������ó�� �����ϴ� ��ü�̴�

	����Ʈ �����͸� ���� �����غ���

	�Ʒ� ���������� delete ������ �ڵ����� �̷�� ����
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { 
		
		cout << "Point ��ü ����" << endl;
	}

	~Point() {

		cout << "Point ��ü �Ҹ�" << endl;
	}

	void SetPos(int x, int y) {

		xpos = x;
		ypos = y;
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

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

		delete posptr;	// �����Ҵ� ���� �ʾҴµ��� delete ������ ����
						// ����Ʈ �����ʹ� new�� �̿��� ���� �Ҵ�� ��ü�� �ּ� ��
						// �̶�� ������ ���ԵǾ� �ִ�
	}
};

int main(void)
{

	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(3, 4));
	SmartPtr sptr3(new Point(4, 5));

	cout << *sptr1;	// ��ü�� ��� ������ ����
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(40, 50);

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
}