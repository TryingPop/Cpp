/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : ���� 409p ����1
	������ �����ε��� �����ϴ� ���� ���� ����� �����ڸ� ���� �����ε� �� ���� ���̴�.
	�����ڸ� �����ε� �ϴ� �������� �ڽ��� �������� ���� �κ��� �巯���鼭,
	�� �κ��� �����ϰ� �Ǵ� ��찡 ���� �����̴�.
	���� �ռ� ���� GFuncionOverloading.cpp(���� 407p)���� ���� Point Ŭ������ �������
	�Ʒ��� �䱸��� �����ڸ� �����ε� �غ���.

	Point Ŭ������ ���ؼ� ���� ������ �����ϴ� ���·� - �����ڸ� �����ε��غ���
		�����Լ� ������� �����ε�
		��� �� - ������ ����� ���� Point ��ü�� ��ȯ
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

	friend Point& operator-(Point&, Point&);
};

Point& operator-(Point& pos1, Point& pos2) {

	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int main(void) 
{

	Point pos1(1, 2);
	Point pos2(3, 5);

	Point cpy;
	cpy = pos1 - pos2;
	cpy.ShowPosition();
	return 0;
}