/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 626p

	������� : String Ŭ������ ����
*/

#ifndef __STRING_H__
#define __STRING_H__

#include "10_BankingCommonDecl.h"

class String {

private:
	int len;
	char* str;

public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};

#endif
