/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : ��������
	���� p150 ~ 153

	��ü�� ������ �������� Ŭ������ �������Ѵ�
	���� Ŭ������ �Ǳ� ���� �ּ����� ������ �������а� ĸ��ȭ�� �ִ�

	�Ʒ� ������ ����,
	Point�� ���� 0�̻� 100���ϰ� �ǰ� ���
	upLeft�� x���� lowRight�� x������ �۰ų� ���ƾ��Ѵ�
	�׸��� upLeft�� y���� lowRight�� y������ �۰ų� ���ƾ��Ѵ�

	�׷��� ���α׷��Ӱ� �Ǽ��� ���� ��,
	��Ե� �߰��� �Ǿ���ϴµ�

	���������δ� ������ ���� ������ �����Ϸ��� ���� �ڵ带 ���� ���� �ʴ´�
	������ ���ѵ� ��������� ���ٸ� ����� �ؼ� �߸��� ���� ������� �ʵ��� ���;� �ϰ�,
	�� �Ǽ��� ���� �� ���� �߰ߵǵ��� �ؾ��Ѵ�
*/

#include <iostream>

using namespace std;

class Point
{

public:
	int x;
	int y;
};

class Rectangle
{

public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{

		cout << "�� ���: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl;
	}
};

int main(void)
{

	// public ������ �ؼ� �ܺο��� �ʱ�ȭ�� ����
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2, pos1 };
	rec.ShowRecInfo();
	return 0;
}