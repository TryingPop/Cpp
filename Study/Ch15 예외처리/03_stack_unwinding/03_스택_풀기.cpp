/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ���� Ǯ��
	���ܰ� ó������ �ʾƼ�, �Լ��� ȣ���� �������� ���� �����Ͱ� ���޵Ǵ� ������ ������
	���� Ǯ���� �Ѵ�
*/

#include<iostream>
using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{


	// SimpleFuncOne > SimpleFuncTwo > SimpleFuncThree ������ �Լ� �����̵ǰ�
	// SimpleFuncThree���� ���� �߻� > SimpleFuncTwo > SimpleFuncOne > main ������ ���� �����Ͱ� ���޵ȴ�
	// ���� ���ο��� ���� ó���� ���� �ʴ´ٸ�, terminate �Լ��� ȣ��Ǹ鼭 ���α׷��� ����ȴ�
	try {

		SimpleFuncOne();
	}
	catch (int expn) {

		cout << "�����ڵ�: " << expn << endl;
	}

	return 0;
}

void SimpleFuncOne(void) {

	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void) {

	cout << "SimpleFuncTwo(void)" << endl;
	SimpleFuncThree();
}

void SimpleFuncThree(void) {

	cout << "SimpleFuncThree(void)" << endl;
	throw - 1;
}