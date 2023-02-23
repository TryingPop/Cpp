/*
��¥ : 2023. 2. 24
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

template<typename T>
void SwapData(T& data1, T& data2) {

	T temp = data1;
	data1 = data2;
	data2 = temp;
}

int main(void)
{

	Point pos1(3, 4);
	Point pos2(10, 20);

	SwapData(pos1, pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}