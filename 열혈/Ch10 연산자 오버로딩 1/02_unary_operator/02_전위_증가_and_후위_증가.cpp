/*
��¥ : 2023. 2. 13
�̸� : �輺��
���� : ���� ������ ���� ������ ����
	���� ������ ���� ���� �Լ��� �����ϴ� ���

	���ڿ� int�� �ִ��� �������� �����Ѵ�
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

	// ���� ����
	Point& operator++() {

		xpos += 1;
		ypos += 1;
		return *this;
	}

	// ���� ����
	// const ��ȯ�� ����!
	const Point operator++(int) {

		const Point retobj(xpos, ypos);	// const Point refobj(*this);
		xpos += 1;
		ypos += 1;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref) {

	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point& ref, int) {

	const Point retobj(ref);	// const ��ü�� �Ѵ�
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}

int main(void)
{

	Point pos(3, 5);
	Point cpy;

	cpy = pos--;
	cpy.ShowPosition();	// [3, 5]
	pos.ShowPosition();	// [2, 4]

	cpy = pos++;
	cpy.ShowPosition();	// [2, 4]
	pos.ShowPosition();	// [3, 5]

	// �̷��� ����� �ݿ��� �����̴�
	int num = 0;
	++(++num);
	// (num++)++;	// ������ ����
	
	return 0;
}