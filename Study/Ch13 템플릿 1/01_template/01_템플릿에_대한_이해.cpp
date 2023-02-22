/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ���ø��� ���� ����
	���ø��� �̿���
	int���� double�� ������ �����ϴ� Add�Լ��� ������  

	�Լ��� ���ø����� �����ϸ�, 
	ȣ�⸶�� �Լ��� �����ϴ��� �Ǵ��ϰ� �������� ������ �Լ��� �����
	���� �Լ��� �����ϸ� ������ ������� �Լ��� ȣ���Ѵ�

	�׸��� �Լ��� ������ �����Ͽ��� �����ȴ�
	���� ���ø��� �̿��ϸ� �����Ͽ����� �ӵ��� ��������
	���� �ӵ��� �������°� �ƴϴ�
*/

#include <iostream>

using namespace std;

// typename ���� class �� �̿��ص� �ȴ�
// T ���� �ٸ� ���� �̿밡��
template <typename T>
T Add(T num1, T num2) {

	return num1 + num2;
}

int main(void)
{

	cout << Add<int>(15, 20) << endl;			// 35
	cout << Add<double>(2.9, 3.7) << endl;		// 6.6
	cout << Add<int>(3.2, 3.2) << endl;			// 6
	cout << Add<double>(3.14, 2.75) << endl;	// 5.89

	cout << Add(15, 20) << endl;				// 35
	cout << Add(2.9, 3.7) << endl;				// 6.6
	cout << Add(3.2, 3.2) << endl;				// 6.4
	cout << Add(3.14, 2.75) << endl;			// 5.89
	return 0;
}