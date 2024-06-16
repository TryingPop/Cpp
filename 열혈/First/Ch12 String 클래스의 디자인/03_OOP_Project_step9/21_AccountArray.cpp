/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 497p

	코드파일 : BoundCheckAccountPtrArray 클래스의 정의
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