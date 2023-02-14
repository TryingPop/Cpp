/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : cout�� endl
	��ü�� ���¸� ǥ�����ִ� cout�� endl�� ������
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

	// cout�� std �̸����� �ȿ� ����� ostream�� ��ü�̴�
	friend ostream& operator<<(ostream&, const Point&);
};

// cout ��ü�� ����Լ� �ϳ��� �߰��ؾ��ϴµ� ostream Ŭ������ �����ؾ��Ѵ�
// �̴� �Ұ����� ����̹Ƿ� �����Լ��� ���� ����� �̿��Ѵ�
ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{

	Point pos1(1, 3);
	cout << pos1;

	Point pos2(101, 303);
	cout << pos2;
	return 0;
}