/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 예외상황이 발생한 위치와 예외상황을 처리해야 하는 위치가 다른 경우
	함수 내에서 예외 데이터를 전달하면, 
	return 문의 실행을 통한 함수의 종료와 마찬가지로 함수를 완전히 빠져 나오는 꼴이 된다
*/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int StoI(char* str) {

	int len = strlen(str);
	int num = 0;

	for (int i = 0; i < len; i++) {

		if (str[i] < '0' || str[i] > '9') {

			throw str[i];
		}

		// 숫자 변환 코드
		// pow((double)10, (len - 1) - i) 자리 찾는 코드
		// str[i] + (7 - '7') 은 자리수 찾는 코드 뒤에 7 - '7' 대신 - '0'을 해도 된다
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
			cout << "재입력 진행합니다." << endl << endl;
		}
	}

	cout << "프로그램을 종료합니다." << endl;
	return 0;
}