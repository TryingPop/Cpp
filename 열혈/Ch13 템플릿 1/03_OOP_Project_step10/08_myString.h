/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	헤더파일 : String 클래스의 선언
*/

#ifndef __STRING_H__
#define __STRING_H__

#include "10_BankingCommonDecl.h"

class String {

private:
	char* str;
	int len;

public:
	String();
	String(const char* s);
	String(const String& s);

	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);

	~String();
};
#endif
