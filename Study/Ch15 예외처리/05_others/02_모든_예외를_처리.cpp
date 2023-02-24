/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : 모든 예외를 처리
	모든 예외가 자료형에 상관없이 걸려드는 구문 

	다만 예외에 대한 어떠한 정보도 받을 수 없고
	전달된 예외의 종류도 구분이 불가능하다
*/

#include<iostream>
using namespace std;

void ExceptionGenerator(int num) throw(int, char, float){

	if (num == 1) {

		int ex = 0;
		cout << "int" << endl;
		throw ex;
	}
	else if (num == 2) {

		char ex = 'A';
		cout << "char" << endl;
		throw ex;
	}
	else if (num == 3) {

		float ex = 1.1f;
		cout << "float" << endl;
		throw ex;
	}
}


int main(void)
{
	int sel;

	while (1) {

		try {

			cout << "에러 선택(1: int,  2: char, 3: float, 4: 종료): ";
			cin >> sel;

			ExceptionGenerator(sel);
			if (sel == 4) {

				break;
			}
			else {

				cout << "잘못된 입력을 하였습니다." << endl;
				cout << "재입력을 실행합니다." << endl << endl;
			}
		}
		catch (...) {

			cout << "에외가 발생" << endl << endl;
		}
	}

}