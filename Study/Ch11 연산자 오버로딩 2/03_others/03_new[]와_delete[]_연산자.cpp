/*
��¥ : 2023. 2. 16
�̸� : �輺��
���� : new[]�� delete[] ������
	new �����ڸ� �̿��� �迭�Ҵ� �� ȣ��Ǵ� �Լ��̴�
	ȣ��Ǵ� �Լ��� ������ ����
		void* operator new[](size_t size) { ... }

	delete[] ���� �迭�Ҹ� �� ȣ��Ǵ� �Լ��̴�
	ȣ��Ǵ� �Լ��� ������ ����
		void operator delete[](void* adr) { ... }

	�Ʒ��� �����̴�	
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