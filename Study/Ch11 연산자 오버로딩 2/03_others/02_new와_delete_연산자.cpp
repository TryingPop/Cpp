/*
��¥ : 2023. 2. 16
�̸� : �輺��
���� : new�� delete ������
	delete Ű���带 �̿��ϸ�
	�����Ϸ��� ptr�� ����Ű�� �Ҹ��� ���� ȣ��
	�׸��� ������ ���·� ���ǵ� �Լ��� ptr�� ����� �ּ� ���� ����
		void operator delete(void* adr) { ... }
	
	�Ϲ�������
		void operator delete (void* adr) {
			delete[] adr;
		}

	���� �����Ϸ����� void ������ �� ����� delete ������ ������� �ʴ´ٸ�,
		delete[] ((char*)adr);
	�� �ۼ��� �����ϸ� �ȴ�

	���� new�� delete �����ڸ� �����ε��� ������ �غ���

	�������� ������ operator new �� operator delete �� static �Լ��� ���ֵȴ�
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

	// ���� ���� operator new�� ȣ��
	Point* ptr = new Point(3, 4);	// operator new : 8
	cout << *ptr;	// [3, 4]
	delete ptr;		// operator delete()
	return 0;
}