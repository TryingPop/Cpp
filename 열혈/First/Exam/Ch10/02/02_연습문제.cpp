/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : ���� 418p ����2
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

	Point& operator~() {

		Point pos(ypos, xpos);
		return pos;
	}
};


int main(void)
{

	Point pos1(1, 2);
	Point pos2 = ~pos1;

	pos2.ShowPosition();
	return 0;
}