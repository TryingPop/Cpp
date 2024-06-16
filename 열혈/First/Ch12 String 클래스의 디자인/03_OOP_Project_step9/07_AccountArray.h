/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : BoundCheckAccountPtrArray 클래스의 선언
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