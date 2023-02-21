/*
날짜 :
이름 : 배성훈
내용 : myString 클래스
	string 클래스의 선언과 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class myString {

private:
	int len;
	char* str;

public:
	// 생성자, 복사 생성자, 소멸자 선언
	myString();
	myString(const char* s);
	myString(const myString& s);
	~myString();

	// 대입 연산자 +=, ==, + 연산자 오버로딩 선언
	myString& operator=(const myString& s);
	myString& operator+=(const myString& s);
	bool operator==(const myString& s);
	myString operator+(const myString& s);

	// 콘솔 입출력 <<, >> 연산자 오버로딩 선언
	friend ostream& operator<<(ostream& os, const myString& s);
	friend istream& operator>>(istream& is, myString& s);
};

myString::myString() {

	len = 0;
	str = NULL;
}

myString::myString(const char* s) {

	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

myString::myString(const myString& s) {

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

myString::~myString() {

	if (str != NULL) {

		delete[] str;
	}
}

myString& myString::operator=(const myString& s) {

	if (str != NULL) {

		delete[] str;
	}

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

myString& myString::operator+=(const myString& s) {

	len += s.len - 1;	// 문자열 종료 문자 1개 제외 
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);	// 문자열 이어붙이는 함수

	if (str != NULL) {

		delete[] str;
	}
	str = tempstr;
	return *this;
}

bool myString::operator==(const myString& s) {

	// strcmp : 두 문자열이 같은 경우만 0을 반환한다
	return strcmp(str, s.str) == 0 ? true : false;
}

myString myString::operator+(const myString& s) {

	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	myString temp(tempstr);
	delete[] tempstr;

	return temp;
}

ostream& operator<<(ostream& os, const myString& s) {

	os << s.str;
	return os;
}

istream& operator>>(istream& is, myString& s) {

	char str[100];
	is >> str;
	s = myString(str);
	return is;
}

int main(void)
{

	myString str1 = "I like ";
	myString str2 = "string class";
	myString str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) {

		cout << "동일 문자열!" << endl;
	}
	else {

		cout << "동일하지 않은 문자열!" << endl;
	}

	myString str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}