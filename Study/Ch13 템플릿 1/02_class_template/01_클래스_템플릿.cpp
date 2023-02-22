/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : Ŭ���� ���ø�
	���ø��� ������� ��ü ����
	
	�Լ� ���ø��� �޸� ���� ������ �� Ŭ������<�ڷ���> ������
	�κп��� <�ڷ���> ������ �Ұ����ϴ�
*/

#include <iostream>
using namespace std;

template <typename T>
class Point {

private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0)
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void)
{

	Point<int> pos1(3, 4);			
	pos1.ShowPosition();			// [3, 4]

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();			// [2.4, 3.6]

	Point<char> pos3('P', 'F');		// ��ǥ������ ���ڷ� ǥ���ϴ� ��Ȳ�� ǥ��
	pos3.ShowPosition();			// [P, F]
	return 0;
}