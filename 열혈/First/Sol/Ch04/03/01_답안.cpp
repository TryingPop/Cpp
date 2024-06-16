/*
��¥ : 2023. 1. 30
�̸� : �輺��
���� : ���� 190p ����1
	�ռ� ������ ���� 04-2�� �ذ��Ͽ��°�? ��ø� �ص� �����ڸ� �������� ���� ��Ȳ�̱� ������
	������ �ʱ�ȭ �Լ��� ���� �� ȣ���ؼ� Point, Circle, Ring Ŭ������ ��ü�� �ʱ�ȭ�Ͽ���.
	�̶� ������ �信 ���ؼ� ��� Ŭ������ �����ڸ� �����غ���
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x, int y)
		: xpos(x), ypos(y) {
	}

	void ShowPointInfo() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

class Circle {

private:
	int rad;		// ������
	Point center;	// ���� �߽�

public:
	Circle(int x, int y, int r)
		: center(x, y) {
		
		rad = r;
	}

	void ShowCircleInfo() const {

		cout << "radius: " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring {

private:
	Circle inCircle;
	Circle outCircle;

public:
	Ring(int inX, int inY, int inR, int outX, int outY, int outR) 
		: inCircle(inX, inY, inR), outCircle(outX, outY, outR) {
	}

	void ShowRingInfo() const {

		cout << "Inner Circle Info..." << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outCircle.ShowCircleInfo();
	}
};

int main(void)
{

	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}