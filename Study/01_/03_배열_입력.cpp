#include <iostream>		
using namespace std;	

/*

��¥ : 2023. 1. 21
�̸� : �輺��
���� : �迭 �Է�
	iostream �ش���
	std::cin �迭 �Է°���
*/

int main()
{

	// ���� ���� ���� ����
	char name[100], lang[100];


	cout << "�̸��� �Է����ּ��� : ";
	cin >> name;

	cout << "�����ϴ� �� �Է����ּ��� : ";
	cin >> lang;
		

	//�Է��� ���ڸ� �����ش�
	cout << "�Է��Ͻ� ���ڴ� " << name << "�Դϴ�.\n";
	cout << "�Է��Ͻ� ���ڴ� " << lang << "�Դϴ�." << endl;
}
