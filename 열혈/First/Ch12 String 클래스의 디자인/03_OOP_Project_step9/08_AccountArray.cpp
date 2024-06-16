/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	�ڵ����� : BoundCheckAccountPtrArray Ŭ������ ����
*/

#include "07_AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len)
	: arrlen(len) {

	arr = new ACC_PTR[len];
}

ACC_PTR& BoundCheckAccountPtrArray::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

ACC_PTR BoundCheckAccountPtrArray::operator[](int idx) const {

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

	for (int idx = 0; idx < arrlen; idx++) {

		delete arr[idx];
	}
	
	delete[] arr;
}