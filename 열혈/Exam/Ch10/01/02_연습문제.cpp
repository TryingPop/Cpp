/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : ���� 409p ����2
	Point Ŭ������ ���ؼ� ���� ������ �����ϴ� ���·� += �����ڿ� -= �����ڸ� �����ε� �غ���
		����Լ� ������� �����ε�
		���� 'pos1 += pos2'�� ����� pos1�� ������� ���� pos2�� ������� ����ŭ ��� �� ����
		���� 'pos1 -= pos2'�� ����� pos1�� ������� ���� pos2�� ������� ����ŭ ��� �� ����
		������ ����� ���� ���� �� ������ pos1�� ��ü�� ��ȯ�ϵ���(�̿��̸� ���������� ��ȯ�ϵ���) ������ �����ε�
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

	Point& operator+=(const Point& pos) {

		xpos += pos.xpos;
		ypos += pos.ypos;
		return *this;
	}

	Point& operator-=(const Point& pos) {

		xpos -= pos.xpos;
		ypos -= pos.ypos;
		return *this;
	}
};

int main(void)
{

	Point pos1(1, 2);
	Point pos2(3, 4);

	pos1 += pos1;
	pos1.ShowPosition();

	(pos2 -= pos1).ShowPosition();

	return 0;
}