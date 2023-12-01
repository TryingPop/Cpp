/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : BoundCheckAccountPtrArray Ŭ������ ����
*/

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "03_Account.h"

typedef Account* ACC_PTR;

class BoundCheckAccountPtrArray {

private:
	ACC_PTR* arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& ref) { }
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& ref) { }

public:
	BoundCheckAccountPtrArray(int len = 100);

	ACC_PTR& operator[](int idx);
	ACC_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};

#endif