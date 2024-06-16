/*
��¥ : 2023. 2. 13
�̸� : �輺��
���� : operator+ ��� �̸��� �Լ�
	operator+ �Լ� ����

	�Լ��� �̸��� �̿��� ȣ��Ӹ� �ƴ϶�, �����ڸ� �̿��� �Լ��� ȣ�⵵ ���
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// ���� �����ڿ� ���� ������ ���� ��Ģ ����
	// const ���� �����ϴ�
	Point operator+(const Point& ref) {

		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void)
{

	Point pos1(3, 4);
	Point pos2(10, 20);

	Point pos3 = pos1.operator+(pos2);
	// pos3�� ���·� ��ȯ�ؼ� �д´�
	Point pos4 = pos1 + pos2;

	pos1.ShowPosition();	// [3, 4]
	pos2.ShowPosition();	// [10, 20]
	pos3.ShowPosition();	// [13, 24]
	pos4.ShowPosition();	// [13, 24]
	return 0;
}