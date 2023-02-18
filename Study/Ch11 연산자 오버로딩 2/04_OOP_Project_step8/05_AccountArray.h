/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : BoundCheckAccountPtrArray 클래스 선언

	배열의 인덱스를 알아서 체크하는 Account 배열 클래스 이다
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "01_Account.h"

typedef Account* ACC_PTR;

class BoundCheckAccountPtrArray {

private:
	ACC_PTR* arr;
	int arrlen;

	// 복사 또는 대입을 막기 위한 코드
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) { }
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) { }

public:
	BoundCheckAccountPtrArray(int len = 100);

	// 인덱스 체크용
	ACC_PTR& operator[] (int idx);
	ACC_PTR& operator[] (int idx) const;

	int GetArrLen() const;

	~BoundCheckAccountPtrArray();
};

#endif
