/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ���� 535p ����1
	���ڷ� ���޵Ǵ� �� ������ ����� ���� ���� ��ȯ�ϴ� SwapData��� �̸��� �Լ��� ���ø����� �����غ���.
	�׸��� ���� Point Ŭ������ ������� ���� ��ȯ�� �̷����� Ȯ���� �� �ֵ��� main �Լ��� �����غ���.

	class Point {

	private:
		int xpos, ypos;

	public:
		Point(int x = 0, int y = 0) 
			: xpos(x), ypos(y) { }

		void ShowPosition() const {
			
			cout << '[' << xpos << ", " << ypos << ']' << endl;
		}
	};
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
};

template <typename T>
void SwapData(T& a, T& b) {

	T temp = a;
	a = b;
	b = temp;
}

int main(void)
{

	Point pos1(3, 4);
	Point pos2(5, 6);

	SwapData(pos1, pos2);

	pos1.ShowPosition();	// [5, 6]
	pos2.ShowPosition();	// [3, 4]
	return 0;
}