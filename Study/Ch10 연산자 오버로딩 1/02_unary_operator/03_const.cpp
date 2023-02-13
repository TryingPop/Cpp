/*
��¥ : 2023. 2. 13
�̸� : �輺��
���� : ���� ���������� const
	���� ���������� const
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

	// ��ȯ�ϴ� ��ü�� const ��ü�� �ϰڴٴ� �ǹ�
	// �� const �Լ��� ȣ�⸸ ���
	const Point operator++(int) {

		const Point retobj(*this);	// �� �Լ� ������ retobj �� ����ȯ�� ��� X
									
		xpos++;
		ypos++;
		return retobj;	// ��ü�� ���� �����Ǳ⿡ const Point reobj�� const ������ ��ȯ���� �ƹ��� ���� X
	}
};

int main(void)
{

	Point pos1(1, 2);
	Point cpy;
	
	cpy = pos1++;
	cpy.ShowPosition();	// [1, 2]

	cpy++;
	cpy.ShowPosition();	// [2, 3]


	const Point pos2(3, 4);
	// Point& ref1 = pos2;	// ������ ����

	const Point& ref2 = pos2;
	// pos2++; // ������ ����
	// (pos1++)++;	// ���� ������ ������ ����
	return 0;
}