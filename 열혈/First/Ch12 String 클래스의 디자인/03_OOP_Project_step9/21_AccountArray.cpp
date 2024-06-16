/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 497p

	�ڵ����� : BoundCheckAccountPtrArray Ŭ������ ����
*/

// Banking
#include "22_BankingCommonDecl.h"
#include "20_AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) 
	: arrlen(len) {

	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[] (int idx) const {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
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