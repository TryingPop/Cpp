/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : String Ŭ������ ����
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
