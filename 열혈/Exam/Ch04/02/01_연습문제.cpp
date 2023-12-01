/*
��¥ : 2023. 1. 30
�̸� : �輺��
���� : ���� 166p ����1
	������ Point Ŭ������ ������� �Ͽ�(Ȱ���Ͽ�) ���� �ǹ��ϴ� Circle Ŭ������ ��������.

	class Point{

	private:
		int xpos, ypos;

	public:
		void Init(int x, int y) {

			xpos = x;
			ypos = y;
		}

		void ShowPointInfo() const {

			cout << '[' << xpos << ", " << ypos << ']' << endl;
		}
	};

	Circle��ü���� ��ǥ���� ��ġ ����(���� �߽���ǥ)�� �������� ���� ������ ���� �� ����� �� �־�� �Ѵ�. 
	�׸��� �������� ������ Circle Ŭ������ ������� Ring Ŭ������ ��������.
	���� �� ���� ������ ǥ�� �����ϹǷ�(�ٱ��� ���� ���� ��), �� ���� Circle ��ü�� ������� ���ǰ� �����ϴ�.
	����� ���� ���� �ٱ��� ���� �߽���ǥ�� �����ϴٸ� �β��� ������ ���� ǥ���ϴ� ���̵Ǹ�,
	�߽���ǥ�� �������� �ʴٸ� �β��� �������� ���� ���� ǥ���ϴ� ���� �ȴ�.
	�̷��� �ؼ� Ŭ������ ���ǰ� �Ϸ�Ǿ��ٸ�, ���� main �Լ��� ������� ������ ��Ű��.

	int main(void) {
		
		Ring ring;
		ring.Init(1, 1, 4, 2, 2, 9);
		ring.ShowRingInfo();
		return 0;
	}

	Init�� �Լ�ȣ���� ���ؼ� ���޵� 1, 1, 4�� ���� ���� ������ �ش��ϸ�(������� X��ǥ, Y��ǥ, ������),
	�̾ ���޵� 2, 2, 9�� �ٱ��� ���� ������ �ش��Ѵ�(������� X��ǥ, Y��ǥ, ������).
	�׸��� �������� ������ ���ų� �����ؾ� �Ѵ�.

	������ ��
		Inner Circle Info...
		radius: 4
		[1, 1]
		Outter Circle Info...
		radius: 9
		[2, 2]

	����� �ϳ��� Ŭ������ �����ϴ���, �׻� ĸ��ȭ�� ����ϱ� �ٶ���.
	�� ������ ��ȵ� ĸ��ȭ�� ���� ��ο��ο� ���� ���̸� ���� �� �ִ�.
*/
#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	void Init(int x, int y) {

		xpos = x;
		ypos = y;
	}

	void ShowPointInfo() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

class Circle {

private:
	Point center;
	int radius;

public:
	void Init(int x, int y, int r) {

		center.Init(x, y);
		radius = r;
	}

	void ShowCircleInfo() const {

		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {

private:
	Circle inner;
	Circle outter;

public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2) {

		inner.Init(x1, y1, r1);
		outter.Init(x2, y2, r2);
	}

	void ShowRingInfo() const {

		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};

int main(void)
{

	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}