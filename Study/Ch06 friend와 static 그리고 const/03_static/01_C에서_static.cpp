/*
��¥ : 2023. 2. 2
�̸� : �輺��
���� : C���� static Ű����
	���������� ����� static : ����� ���� �������� ������ ���
	�Լ� ���� ����� static : �ϳ͸� �ʱ�ȭ�ǰ�, ���������� �޸� �Լ��� ���������� �Ҹ���� �ʴ´�
*/

#include <iostream>
using namespace std;

void Counter() {

	static int cnt;
	cnt++;
	cout << "Current cnd: " << cnt << endl;
}

int main(void) 
{

	for (int i = 0; i < 10; i++) {

		Counter();
	}
	
	return 0;
}