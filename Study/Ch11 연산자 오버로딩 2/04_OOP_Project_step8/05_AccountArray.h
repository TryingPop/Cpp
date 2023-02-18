/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : BoundCheckAccountPtrArray Ŭ���� ����

	�迭�� �ε����� �˾Ƽ� üũ�ϴ� Account �迭 Ŭ���� �̴�
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "01_Account.h"

typedef Account* ACC_PTR;

class BoundCheckAccountPtrArray {

private:
	ACC_PTR* arr;
	int arrlen;

	// ���� �Ǵ� ������ ���� ���� �ڵ�
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) { }
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) { }

public:
	BoundCheckAccountPtrArray(int len = 100);

	// �ε��� üũ��
	ACC_PTR& operator[] (int idx);
	ACC_PTR& operator[] (int idx) const;

	int GetArrLen() const;

	~BoundCheckAccountPtrArray();
};

#endif
