/*
��¥ : 2023. 1. 24
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

#include <iostream>
using namespace std;

typedef struct __Point {

	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main(void)
{

	// ������ struct ���� ���
	// Point p1 = { 1, 1 };
	// Point p2 = { 2, 2 };
	
	// new�� �̿��� Point ���� �� ���� ����
	// new�� ��ȯ ���� �ش� ������ ptr�̹Ƿ� �տ� *�� �ٿ� Point�� ����Ű�� �Ѵ�
	Point* ptrPnt1 = new Point{ -2, 0 };	// xpos = -2, ypos = 0
	Point* ptrPnt2 = new Point{ 1, 1 };		// xpos = 1, ypos = 1 
	
	Point &p3 = PntAdder(*ptrPnt1, *ptrPnt2);

	cout << "p3.xpos : " << p3.xpos << endl;
	cout << "p3.ypos : " << p3.ypos << endl;

	// �޸� ����
	delete ptrPnt1;
	delete ptrPnt2;
	delete &p3;

	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2) {

	// malloc���� addPnt ����
	// Point* addPnt = (Point*)malloc(sizeof(Point) * 1);

	// ���� ���ǿ� �°� addPnt����
	Point* addPnt = new Point;

	// ���� �����ϴ� ���
	addPnt->xpos = p1.xpos + p2.xpos;
	addPnt->ypos = p1.ypos + p2.ypos;

	return *addPnt;
}