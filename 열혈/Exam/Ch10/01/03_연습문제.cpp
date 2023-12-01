/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : ���� 410p ����3
	Point Ŭ������ ���ؼ� ���� ������ �����ϴ� ���·� == �����ڿ� != �����ڸ� �����ε� �غ���.
		�� �� �����Լ��� ���·� �����ε�
		���� 'pos1 == pos2'�� ����� ��� ����� ���� ���ٸ� true, �׷��� �ʴٸ� false ��ȯ
		���� 'pos1 != pos2'�� ����� ��� ����� ���� ���ٸ� false, �׷��� �ʴٸ� true ��ȯ
		������ ==�� ���� �����ε� �� ������, �̸� �̿��ϴ� ���·� != �����ڸ� �����ε�

	����� �� 3���������� �ϳ��� ��ȿ� �� ��θ� ��Ƶ� �ȴ�.
	������ ���� �׷��� ���·� ����� ����
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

	friend bool operator==(Point&, Point&);
	friend bool operator!=(Point&, Point&);
};

bool operator==(Point& pos1, Point& pos2) {

	if (pos1.xpos != pos2.xpos) {

		return false;
	}

	if (pos1.ypos != pos2.ypos) {

		return false;
	}

	return true;
}

bool operator!=(Point& pos1, Point& pos2) {

	return !(pos1 == pos2);
}

int main(void)
{

	Point pos1(1, 2);
	Point pos2(3, 4);
	Point pos3(1, 2);

	cout << "pos1 == pos3 : ";

	if (pos1 == pos3) {

		cout << "true" << endl;
	}
	else {

		cout << "false" << endl;
	}

	cout << "pos1 != pos2 : ";

	if (pos1 != pos2) {

		cout << "true" << endl;
	}
	else {

		cout << "false" << endl;
	}
	
	return 0;
}