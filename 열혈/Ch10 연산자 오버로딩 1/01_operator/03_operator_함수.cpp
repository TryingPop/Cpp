/*
��¥ : 2023. 2. 13
�̸� : �輺��
���� : operator �Լ�
	��� �� ������
		��� ���� ������ .
		��� ������ ������ .*
		���� ���� ������ ::
		���� ������(3�� ������) ?:
		����Ʈ ���� ũ�� ��� sizeof
		RTTI���� ������ typeid
		����ȯ ������ static_cast
		����ȯ ������ dynamic_cast
		����ȯ ������ const_cast
		����ȯ ������ reinterpret_cast

	C++ �� ���� ��Ģ�� �����ϱ� ���ؼ� �̵� �����ڿ� ���ؼ� operator �Լ��� �̿��� �� ����
	
	��� �Լ� ������� ������ ������
		���Կ����� =
		�Լ� ȣ�� ������ ()
		�迭 ���� ������(�ε��� ������) []
		��� ������ ���� ������ ������ ->

	�̵��� ��ü�� ������� �����ؾ� �ǹ̰� ���ϴ� �����ڵ��̱� ������,
	��� �Լ� ������θ� �������� �����ε��� ����Ѵ�

	�̿ܿ��� ������ ����
		�������� �켱������ ���ռ��� �ٲ��� �ʴ´�
		�Ű������� ����Ʈ �� ������ �Ұ����ϴ�

	������ ������� ���� ������ ������ ������ ������ ����
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public :
	Point(int x = 0, int y = 0) 
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// ���� ���� ������ �ʴ� ���´� ����
	void operator+(const Point& ref) {

		xpos += ref.xpos;
		ypos += ref.ypos;
	}
};

/*
// �������� ���� ��ɱ��� ������ �� ����
// �������� �⺻ ����� �����ϴ� ������ ������ �����ε��� ������ �ʴ´�
int operator+(const int num1, const int num2) {

	return num1 * num2;
}
*/

int main(void)
{
	
	Point pos1(1, 2);
	Point pos2(3, 4);

	pos1 + pos2;

	pos1.ShowPosition();	// [4, 6]
	pos2.ShowPosition();	// [3, 4]
	return 0;
}