/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : ���� 57p ����2
	���α׷� ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� ���·� �Է� �޾Ƽ�,
	�Է� ���� �����͸� �״�� ����ϴ� ���α׷��� �ۼ��� ����.
*/

#include <iostream>

int main(void) 
{
	
	char name[50];
	char phoneNumber[50];

	std::cout << "�̸�: ";
	std::cin >> name;
	std::cout << "��ȭ��ȣ: ";
	std::cin >> phoneNumber;

	std::cout << "����� �̸�: " << name << std::endl;
	std::cout << "����� ��ȭ��ȣ: " << phoneNumber << std::endl;
	return 0;
}