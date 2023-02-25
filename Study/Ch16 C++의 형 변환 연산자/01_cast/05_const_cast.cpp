/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : const_cast
	���� dynamic_cast�� static_cast�� ������ ����ϴ�

	const_cast �������� ������ ������ ����
		const_cast<T>(expr)

		const_cast�� const ������ �����ϴ� �� ��ȯ�� �������� ����Ѵ�

	const �������� ���� ���� ����ġ�� �߻���
	������ ������ �Ұ����� ��쿡 �����ϰ� ����̵ȴ�
	���� volatile�� ������ �����ϴµ��� ����� �� �ִ�
	�Ʒ��� ���� �����̴�
*/

#include <iostream>
using namespace std;

void ShowString(char* str) {

	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2) {

	cout << n1 + n2 << endl;
}


int main(void)
{

	const char* name = "Lee Sung Ju";
	// ShowString(name);			// ȣȯ �ȵǴ� ������ ����
	// �ݴ�� ShowString�� ���ڰ� const char*�̰�
	// name�� char*�� ���ǵǾ��� ������ ȣȯ�� �����ϴ�
	ShowString(const_cast<char*>(name));	// Lee Sung Ju

	const int& num1 = 100;
	const int& num2 = 200;

	// ShowAddResult(&num1, &num2);	// ȣȯ �ȵǴ� ������ ����
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));	// 300
	return 0;
}