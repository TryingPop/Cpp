/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : ���� 418p ����1
	���� OneOpndOverloading.cpp(���� 414p)���� ���� 
	Point Ŭ������ ������� �Ʒ��� �䱸��� �����ڸ� �����ε� �غ���.

	��ȣ �����ڷμ� -�� ���� �������̴�.
	�� �����ڴ� �ǿ������� ��ȣ�� ������Ų ����� ��ȯ�Ѵ�.
	������� ���� ������ ����Ǹ�,
		int num2 = -num1;

	num2���� num1�� ���밪�� ������ ��ȣ�� �ٸ� ���� ����ȴ�.
	���� num1�� ������ ������ ��ġ�� �ʴ´�.
	�̿� �����ϰ� Point Ŭ������ ������� - �����ڸ� �����ε� �غ���.
	������ ������ ����Ǹ�,
		Point pos2 = -pos1;

	pos2�� ��������� pos1�� ������� ���� �ٸ� ��ȣ�� ������ �ʱ�ȭ�ǵ��� �����ε� �غ���.
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

	friend Point& operator-(const Point&);
};

Point& operator-(const Point& ref) {

	Point pos(-ref.xpos, -ref.ypos);
	return pos;
}

int main(void)
{

	Point pos1(2, 3);
	Point pos2 = -pos1;

	pos2.ShowPosition();
	return 0;
}