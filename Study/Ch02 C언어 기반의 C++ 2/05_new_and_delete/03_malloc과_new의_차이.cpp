/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : malloc�� new�� ����
	Ŭ������ ������ �� new�� delete�� ���� �����ڿ� �Ҹ��ڸ� ȣ���ϰ� �˾Ƽ� ������ ����ȯ�� �Ѵ�
	�ݸ� malloc�� free�� �����ڿ� �Ҹ��ڸ� ȣ������ ���ϰ� ���� ���޵� �ȵȴ�

	malloc�� ��� realloc�� �̿��� ���������� �޸𸮸� ���� �� �� �ִ�
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple {

	//���� ������ �� ������
public :
	Simple() {

		cout << "I am simple constructor!" << endl;
	}
};

int main(void) 
{

	cout << "case 1 : ";
	Simple* sp1 = new Simple;	// ������ ȣ��

	cout << "case 2 : ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);	// ������ ȣ�� X

	cout << endl << "end of main" << endl;

	delete sp1;
	free(sp2);
	return 0;
}