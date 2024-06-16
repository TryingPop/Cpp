/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : catch구문 주의사항
	예외가 발생하면 예외 데이터를 전달받을 수 있는 catch 블록을 위에서 아래로 찾아 내려간다
	그리고 적절한 catch 블록을 찾게 되면, 해당 catch 블록이 실행되면서 예외의 처리는 완료가 된다

	이러한 특성 때문에 블록배치를 주의하자
*/

#include<iostream>
using namespace std;

class AAA {

public:
	void ShowYou() {

		cout << "AAA exception!" << endl;
	}
};

class BBB : public AAA {

public:
	void ShowYou() {

		cout << "BBB exception!" << endl;
	}
};

class CCC : public BBB {

public:
	void ShowYou() {

		cout << "CCC exception!" << endl;
	}
};

void ExceptionGenerator(int expn) {

	if (expn == 1) {

		throw AAA();
	}
	else if (expn == 2) {

		throw BBB();
	}
	else {

		throw CCC();
	}
}

int main(void) {

	try {

		ExceptionGenerator(3);				// CCC Exception 생성
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (AAA& expn) {

		cout << "catch(AAA& expn)" << endl;	// 출력
		expn.ShowYou();						// AAA exception 출력
	}
	catch (BBB& expn) {

		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC& expn) {

		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}

	// 서로 매칭되는 경우를 출력하려면 아래와 같이 하면된다
	try {

		ExceptionGenerator(3);				// CCC Exception 생성
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (CCC& expn) {

		cout << "catch(CCC& expn)" << endl;	// 출력
		expn.ShowYou();						// CCC Exception 출력
	}
	catch (BBB& expn) {

		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA& expn) {

		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	return 0;
}