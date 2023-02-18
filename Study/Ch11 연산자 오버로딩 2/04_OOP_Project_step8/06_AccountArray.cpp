/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : BoundCheckAccountPtrArray Ŭ���� ����
*/

#include "05_AccountArray.h"
#include <cstdlib>

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len)
	: arrlen(len) {

	arr = new ACC_PTR[len];
}

ACC_PTR& BoundCheckAccountPtrArray::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "�ε��� ������ ��ġ���� �ʽ��ϴ�" << endl;
		exit(1);
	}
	
	return arr[idx];
}

ACC_PTR& BoundCheckAccountPtrArray::operator[](int idx) const {

	if (idx < 0 || idx >= arrlen) {

		cout << "�ε��� ������ ��ġ���� �ʽ��ϴ�" << endl;
		exit(1);
	}
	
	return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const {

	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {

	delete[] arr;
}