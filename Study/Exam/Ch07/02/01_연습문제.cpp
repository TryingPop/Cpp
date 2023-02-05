/*
��¥ : 2023. 2. 6
�̸� : �輺��
���� : ���� 312p ����1
	���簢���� �ǹ��ϴ� Square Ŭ������ ���簢���� �ǹ��ϴ� Rectangle Ŭ������ �����ϰ��� �Ѵ�
	class Rectangle {

		...
	};

	class Square : public Rectangle {

		...
	};

	�̿� ���� main �Լ��� �Բ� ������ �����ϵ��� ���� Ŭ������ �ϼ��غ���.
	����� ����� �Ѵٰ��ؼ� ���� Ŭ������ �����ΰ��� ���� ��ƾ� �Ѵٴ� ������ ������!

	[main �Լ�]
	int main(void)
	{

		Rectangle rec(4, 3);
		rec.ShowAreaInfo();

		Square sqr(7);
		sqr.ShowAreaInfo();
		return 0;
	};

	[������ ��]
	���� : 12
	���� : 49
*/

#include <iostream>
using namespace std;

class Rectangle {

private:
	int width;
	int height;

public:
	Rectangle(int x)
		: width(x), height(x) { }

	Rectangle(int w, int h)
		: width(w), height(h) { }

	void ShowAreaInfo() {

		cout << "����: " << width * height << endl;
	}
};

class Square : public Rectangle 
{ 
public:
	Square(int x)
		: Rectangle(x) { }
};

int main(void)
{

	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}
