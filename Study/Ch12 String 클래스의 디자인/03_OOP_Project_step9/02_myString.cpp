/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : String 클래스의 정의
*/

#include "01_myString.h"

String::String() {

	len = 0;
	str = NULL;
}

String::String(const char* s) {

	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s) {

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String() {
	if (str != NULL) {

		delete[] str;
	}
}

String& String::operator=(const String& s) {

	if (str != NULL) {

		delete[] str;
	}

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}

String& String::operator+=(const String& s) {

	char* tempstr;
	len = len + s.len - 1;

	tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if (str != NULL) {

		delete[] str;
	}

	str = tempstr;
	return *this;
}

bool String::operator==(const String& s) {

	return strcmp(str, s.str) == 0 ? true : false;
}

String String::operator+(const String& s) {

	char* tempstr = new char[len + s.len - 1];

	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String str(tempstr);

	return str;
}

ostream& operator<<(ostream& os, const String& s) {

	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) {

	char* str = new char[100];
	is >> str;

	s = String(str);

	return is;
}