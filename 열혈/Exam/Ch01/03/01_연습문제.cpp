#include <iostream>
using namespace std;

/*

��¥ : 2023. 1. 22
�̸� : �輺��
���� : ���� 32p ����1
	����[ DefaultValue3.cpp�� ���ǵ� �Լ� BoxVolume�� '�Ű������� ����Ʈ �� ����' ���°� �ƴ�,
	'�Լ��� �����ε�'�� ���·� �� �����غ���. ���� main �Լ��� �������� ���Ͼ� �ϸ�,
	�������� �����ؾ� �Ѵ�.
*/

// �Լ� ����
int BoxVolume(int length) {

	return length;
}

int BoxVolume(int length, int width) {

	return length * width;
}

int BoxVolume(int length, int width, int height) {

	return length * width * height;
}

int main(void)
{

	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 6, d] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
//	cout << "[D, D, D] : " << BoxVolume() << endl;

	return 0;
}

