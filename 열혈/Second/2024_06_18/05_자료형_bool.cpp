/*
��¥ : 2024. 6. 18
�̸� : �輺��
���� : �ڷ��� bool
	���� p66 ~ 67

	true�� false�� �� ��ü�� ���� ������ �ǹ��ϴ� �������̱� ������,
	�̵� �������� ������ ���� �ڷ����� ������ ���ǵǾ� �ִ� ���� �翬�ϴ�

	true�� false�� ������ bool �� �����Ͷ� �Ѵ�
	bool�� int, double�� ���������� �⺻ �ڷ����� �ϳ��̱⿡
	bool �� ������ �����ϴ� ���� �����ϴ�
*/

#include <iostream>

using namespace std;

bool IsPositive(int _num)
{

	if (_num <= 0) return false;
	else return true;
}

int main(void)
{

	bool isPos;
	int num;

	cout << "Input number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos) cout << "Positive number" << endl;
	else cout << "Negative number" << endl;

	return 0;
}