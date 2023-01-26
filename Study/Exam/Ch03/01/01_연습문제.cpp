/*
��¥ : 2023. 1. 26
�̸� : �輺��
���� : ���� 114p ����1
	2���� ���󿡼� ��ǥ�� ǥ���� �� �ִ� ����ü�� ������ ���� �����Ͽ���.
	struct Point {

		int xpos;
		int ypos;
	};

	���� ����ü�� ������� ������ �Լ��� �����ϰ��� �Ѵ�(�ڼ��� ����� ������ ���� ���ؼ� Ȯ���ϵ��� �Ѵ�).
	void MovePos(int x, int y);			// ���� ��ǥ�̵�
	void AddPoint(const Point &pos);	// ���� ��ǥ����
	void ShowPosition();				// ���� x, y ��ǥ���� ���

	��, ���� �Լ����� ����ü �ȿ� ���Ǹ� �ؼ� ������ ���·� main �Լ��� ������ �� �־���Ѵ�.

	int main(void)
	{

		Point pos1 = { 12, 4 };
		Point pos2 = { 20, 30 };

		pos1.MovePos(-7, 10);
		pos1.ShowPosition();		// [5, 14] ���
		
		pos1.AddPoint(pos2);
		pos1.ShowPosition();		// [25, 44] ���
		return 0;
	}
*/

#include <iostream>
using namespace std;

typedef struct Point {
	
	int xpos;
	int ypos;

public:
	void MovePos(int x, int y) {

		xpos += x;
		ypos += y;
	};

	void AddPoint(const Point& pos) {

		xpos += pos.xpos;
		ypos += pos.ypos;
	};

	void ShowPosition() {

		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};


int main(void)
{

	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();		// [5, 14] ���

	pos1.AddPoint(pos2);
	pos1.ShowPosition();		// [25, 44] ���
	return 0;
}