/*
날짜 : 2023. 2. 21
이름 : 배성훈
내용 : string 클래스
	string 헤더파일에 정의되어져 있는 string을 알아보자
		string 클래스는 <<, +, += 등 많은 연산자가 오버로딩 되어져 있다
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{

	string str1 = "I like ";	
	string str2 = "string class";
	string str3 = str1 + str2;	

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) {

		cout << "동일 문자열!" << endl;		// 출력
	}
	else {

		cout << "동일하지 않은 문자열!" << endl;
	}

	string str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}