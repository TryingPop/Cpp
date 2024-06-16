/*
��¥ : 2023. 1. 25
�̸� : �輺��
���� : ���� 95p ����1
	����ü�� ���� ������ ���� �� �ִ� ������ �����ϰڴ�.
	2���� ���󿡼��� ��ǥ�� ǥ���� �� �ִ� ����ü�� ������ ���� �����Ͽ���.
	typedef struct __Point{
		int xpos;
		int ypos;
	} Point;
	���� ����ü�� ������� �� ���� ���� ����ϴ� �Լ��� ������ ���·� �����ϰ�(��������� �Լ��� ��ȯ�� ���ؼ� ����Ѵ�),
		Point& PntAdder(const Point &p1, const Point &p2);
	������ �� ���� �����Ͽ�, �� �Լ��� �̿��� ���� ������ �����ϴ� main �Լ��� �����غ���.
	��, ����ü Point ���� ������ ������ ������ new �����ڸ� �̿��ؼ� �����ؾ� �ϸ�,
	�Ҵ�� �޸� ������ �Ҹ굵 ö���ؾ� �Ѵ�. ����� �� ������ �ذ��� ���ؼ��� ���� �� ������ ���� �� �� �־�� �Ѵ�.
		1. �����Ҵ� �� ������ �Լ��� ������ �Ű������� ���ڷ� ��� �����ؾ� �ϴ°�?
		2. �Լ� ���� ����� ������ ���������� ��ȯ�Ϸ��� �ش� ������ ��� �����ؾ� �ϴ°�?
*/

#include<iostream>
using namespace std;

typedef struct __Point {

	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2) {

	Point* pptr = new Point;
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}

int main(void)
{

	Point* pptr1 = new Point;
	pptr1->xpos = 3;
	pptr1->ypos = 30;

	Point* pptr2 = new Point;
	pptr2->xpos = 70;
	pptr2->ypos = 7;

	Point& pref = PntAdder(*pptr1, *pptr2);
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

	delete pptr1;
	delete pptr2;
	delete& pref;
	return 0;
}