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

	~ �����ڴ� ���� �����ڷμ� ��Ʈ���� not�� �ǹ̸� ���´�.
	��, ~ �����ڴ� ��Ʈ������ 1�� 0����, 0�� 1�� �ٲ۴�.
	�̿� �츮�� Point ��ü�� ������� ������ ���� ������ �����ϵ��� ~ �����ڸ� �����ε� �ϰ��� �Ѵ�.
		Point pos2 = ~pos1;
	���� ~ ������ ����� ��ȯ�� ��ü�� xpos ������� pos1�� ypos ����,
	��ȯ�� ��ü�� ypos ������� pos1�� xpos ���� ����Ǿ�� �Ѵ�.

	�̹����� �ϳ��� ��ȿ� ���� �� ������ ���� ���� ��� ��Ƶ� �ȴ�.
	������ �׷��� ���·� ����� ����
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

	Point operator-() {

		Point pos(-xpos, -ypos);
		return pos;
	}

	friend Point operator~(const Point&);
};

Point operator~(const Point& ref) {

	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void)
{

	Point pos1(9, -7);
	pos1.ShowPosition();	// [9, -7]
	Point pos2 = -pos1;
	pos2.ShowPosition();	// [-9, 7]
	(~pos2).ShowPosition();	// [9, -7]
	pos2.ShowPosition();	// [-9, 7]
	return 0;
}