/*
��¥ : 2023. 2. 10
�̸� : �輺��
���� : ��ü�� ����Լ��� ��������� ����
	����ü�� �����Լ��� �̿��� Ŭ������ ��ü�� �䳻����
	��ü�� ����Լ��� ��������� ������ ��� �̷�������� Ȯ��
*/

#include <iostream>
using namespace std;

// Ŭ���� Data�� �䳻 �� ����
typedef struct Data {

	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
};

void ShowData(Data* THIS) {

	cout << "Data: " << THIS->data << endl;
}

void Add(Data* THIS, int num) {

	THIS->data += num;
}

// ������ ����� main�Լ�
int main(void)
{

	// obj1, obj2 �� ShowData�� Add�� ����
	// Ŭ������ �����ϰ� ��������� ��ü ���� ����
	// ����Լ��� �޸��� �Ѱ����� ������ ��ġ�Ѵ�
	// ��, �� �Լ��� ���ǵ� Ŭ������ ��� ��ü�� �̸� �����ϴ� ����
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
}