/*
��¥ : 2023. 2. 25
�̸� : �輺��
���� : new ������
	new ���꿡 ���� �޸� ���� �Ҵ��� �����ϸ� bad_alloc �̶�� ���ܰ� �߻�
	bad_alloc�� ������� new�� ����� ���� Ŭ�����μ� �޸� ������ �Ҵ��� ���������� �˸��� �ǵ��� ����

	�̿� ���õ� ������ ����
*/

#include <iostream>
#include <new>
using namespace std;

int main(void)
{

	int num = 0;

	try {

		while (1) {

			num++;
			cout << num << "��° �Ҵ� �õ�" << endl;	// 1
			new int[1000000][1000000];					// �ٷ� ���� �߻�
		}
	}
	catch (bad_alloc& bad) {

		cout << bad.what() << endl;						// bad allocation
		cout << "�� �̻� �Ҵ� �Ұ�!" << endl;			// ���
	}
}