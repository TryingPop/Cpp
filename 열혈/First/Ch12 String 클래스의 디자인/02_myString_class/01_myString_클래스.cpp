/*
��¥ :
�̸� : �輺��
���� : myString Ŭ����
	string Ŭ������ ����� ����
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
	// ������, ���� ������, �Ҹ��� ����
	myString();
	myString(const char* s);
	myString(const myString& s);
	~myString();

	// ���� ������ +=, ==, + ������ �����ε� ����
	myString& operator=(const myString& s);
	myString& operator+=(const myString& s);
	bool operator==(const myString& s);
	myString operator+(const myString& s);

	// �ܼ� ����� <<, >> ������ �����ε� ����
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

	len += s.len - 1;	// ���ڿ� ���� ���� 1�� ���� 
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);	// ���ڿ� �̾���̴� �Լ�

	if (str != NULL) {

		delete[] str;
	}
	str = tempstr;
	return *this;
}

bool myString::operator==(const myString& s) {

	// strcmp : �� ���ڿ��� ���� ��츸 0�� ��ȯ�Ѵ�
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

		cout << "���� ���ڿ�!" << endl;
	}
	else {

		cout << "�������� ���� ���ڿ�!" << endl;
	}

	myString str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}