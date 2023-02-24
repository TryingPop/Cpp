/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 예외의 명시
	다른 자료형의 예외 데이터가 전달될 경우 
	terminate 함수의 호출로 인해서 프로그램은 종료되어서
	예외 타입을 명시하는게 좋다
	
	아래는 예외 타입을 전달하는 예제이다

	throw () 는 예외를 전달하지 않는다는 의미이다
*/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

// 예외로 int와 char형 자료를 던지는 함수
int StoI(char* str) throw (int, char) {

	int len = strlen(str);
	int num = 0;

	if (len != 0 && str[0] == '0') {

		throw 0;
	}

	for (int i = 0; i < len; i++) {

		if (str[i] < '0' || str[i] > '9') {

			throw str[i];
		}

		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}

	return num;
}

int main(void) 
{

	char str1[100];
	char str2[200];

	while (1) {
		cout << "두 개의 숫자 입력: ";
		cin >> str1 >> str2;
		try {

			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch) {

			cout << "문자 " << ch << "가 입력되었습니다." << endl;
			cout << "재입력을 진행합니다." << endl << endl;
		}
		catch (int expn) {

			if (expn == 0) {

				cout << "0으로 시작하는 숫자는 입력불가." << endl;
			}
			else {

				cout << "비정상적 입력이 이루어졌습니다." << endl;
			}

			cout << "재입력 진행합니다." << endl << endl;
		}
	}

	cout << "프로그램을 종료합니다." << endl;
	return 0;
}