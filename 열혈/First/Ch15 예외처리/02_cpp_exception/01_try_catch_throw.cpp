/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ����ó��
	try : ���ܸ� �߰��Ѵ�
	catch : ���ܸ� ��´�
	throw : ���ܸ� ������

	try catch�� �ϳ��� �����̹Ƿ� ���̿� �ٸ� �ڵ带 ������
	������ ������ �߻��Ѵ�

	���ܰ� �߻����� ������
	catch ����� �ǳʶڴ�

	���ܰ� �߻��ϸ�
	���� �߻��ϸ� ������ try ������ ������� �ʰ�
	�ٷ� catch �������� ����

	C#���� try - catch ����
	python���� try - exception ����

	try ������ ���ܰ� �߻��Ҹ��� �����Ӹ� �ƴ϶�
	�׿� ���õ� ��� ������ �Բ� ��� �̸� �ϳ��� ���� ������ �����ϴ� ���̴�
*/

#include <iostream>
using namespace std;

int main(void)
{

	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2;
	try {

		if (num2 == 0) {

			throw num2;
		}

		cout << "�������� ��: " << num1 / num2 << endl;
		cout << "�������� ������: " << num1 % num2 << endl;

	}
	catch (int ex) {	// ex���� �ƹ� ������ ���� ����
						// throw ���� ���� num2�� �޾ƿ´�

		cout << "������ " << ex << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}
	
	cout << "end of main" << endl;
	return 0;
}