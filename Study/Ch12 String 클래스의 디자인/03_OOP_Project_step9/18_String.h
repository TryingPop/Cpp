/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 521p

	헤더파일 : String 클래스의 선언
*/

#ifndef __STRING_H__
#define __STRING_H__

#include "22_BankingCommonDecl.h"

class String {

private:
	int len;
	char* str;

public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+ (const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, const String s);
};
#endif
