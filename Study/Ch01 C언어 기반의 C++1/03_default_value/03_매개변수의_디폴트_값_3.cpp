#include <iostream>
using namespace std;

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �Ű������� ����Ʈ ��
	����Ʈ ���� �����ʺ��� ��ġ�ؾ��Ѵ�
*/

// �Լ��� ����
int BoxVolume(int length, int width = 1, int height = 1);

int main()
{

	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
//	cout << "[D, D, D] : " << BoxVolume() << endl; // ���� ���

	return 0;
}

// �Լ��� ����
int BoxVolume(int length, int width, int height) {

	return length * width * height;
}
