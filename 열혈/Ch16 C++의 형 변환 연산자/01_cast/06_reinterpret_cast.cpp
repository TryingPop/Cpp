/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : reinterpret_cast
	������� �ڷ��������� ��ȯ

	reinterpret_cast �������� ����
		reinterpret_cast<T>(expr)

		�����͸� ������� �ϴ�, 
		�׸��� �����Ϳ� ������ �ִ� ��� ������ �� ��ȯ�� ����Ѵ�
*/

#include<iostream>
using namespace std;

int main(void) 
{

	int num1 = 0x010203;		// 16������ ���� �־��� �ǹ�
								// 3 * (16)^0 + 0 * (16)^1 + 2 * (16)^2 + 0 * (16)^3 + 1 * (16)^4 + 0 * (16)*5
	
	// cout << num1 << endl;	// 66501

	char* ptr1 = reinterpret_cast<char*>(&num1); // num1�� ���� char�� �д´�
	
	// int num = 0x010000;
	// int num3 = 65536;

	// char* ptr3 = reinterpret_cast<char*>(&num3);
	// cout << static_cast<int>(*ptr3) << endl;	// 0

	// int num4 = 3;
	// char* ptr4 = reinterpret_cast<char*>(&num4);
	// cout << static_cast<int>(*ptr4) << endl;	// 3

	// 3, 2, 1, 0 ���
	for (int i = 0; i < sizeof(num1); i++) {

		// cout << *(ptr1 + i) << endl;				 	// , , ,  
														// 4��°�� ������ ���
														// ���� (char)3, (char)2, (char)1, (char)0�� ���̴�

		cout << static_cast<int>(*(ptr1 + i)) << endl;	// ptr�� char*���̹Ƿ� 1����Ʈ�� �д°� ����
														// �׷��� �ڿ������� ���� 03, 02, 01�� �д´�
														// ���� num1 = 0x010248 �̶� �����ϸ�
														// 72(0x48), 2(0x02), 1(0x01), 0(0x00) �� ����Ѵ�
	}
	
	int num2 = 72;							// 0x48 
	int* ptr2 = &num2;						// ptr2�� num2�� �ּҷ� �Ѵ�

	int adr = reinterpret_cast<int>(ptr2);	// �ּ� ���� ������ ��ȯ 
	cout << "Addr: " << adr << endl;		// �ּ� �� ���
											// ������ �� ���´�

	int* rptr = reinterpret_cast<int*>(adr);// ������ �ٽ� �ּ� ������ ��ȯ
	
	cout << "rptr: " << rptr << endl;		// rptr ����ϴ� ���� 4����Ʈ�� 00000000 or FFFFFFFF �� ��µȴ�
											// rptr�� ���� 8�ڸ�(4����Ʈ)�� 00000000�̸� adr�� ���, FFFFFFFF�̸� adr�� ����

	cout << "value: " << *rptr << endl;		// �ּ� ���� ����� ���� ���
											// *rptr �д°� �ȵǾ� ���α׷��� ���� ����ȴ�

	return 0;
}