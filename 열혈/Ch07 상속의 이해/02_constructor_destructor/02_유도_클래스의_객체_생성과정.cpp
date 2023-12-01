/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 유도 클래스의 객체 생성과정
	상위클래스, 기초클래스, 슈퍼 클래스, 부모 클래스 모두 같은 말이고
	각각에 대응되는 말은 하위 클래스, 유도 클래스, 서브 클래스, 자식 클래스 이다

	유도 클래스를 자식 클래스로 해석하면 된다

	유도 클래스의 객체 생성과정을 알아보는 예이다
	여기서 가장 중요한 것은 기초 클래스의 생성자 호출이다

	메모리 할당 > 기초 클래스 생성자 호출 > 유도 클래스 생성자 호출 순
*/

#include <iostream>
using namespace std;

class SoBase {

private:
	int baseNum;

public:
	SoBase()
		: baseNum(20) {
		
		cout << "SoBase()" << endl;
	}

	SoBase(int n)
		: baseNum(n) {

		cout << "SoBase(int n)" << endl;
	}

	void ShowBaseData() {

		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase {

private:
	int derivNum;

public:
	SoDerived()
		: derivNum(30) {

		cout << "SoDerived()" << endl;
	}

	SoDerived(int n)
		: derivNum(n) {

		cout << "SoDerived(int n)" << endl;
	}

	SoDerived(int n1, int n2)
		: SoBase(n1), derivNum(n2) {

		cout << "SoDerived(int n1, int n2)" << endl;
	}

	void ShowDerivData() {

		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main(void)
{

	cout << "case1....." << endl;
	SoDerived dr1;	// SoBase(), SoDerived() 순으로 호출
	dr1.ShowDerivData();
	cout << "--------------------" << endl;

	cout << "case2....." << endl;
	SoDerived dr2(12);	// SoBase(), SoDerived(int n) 순으로 호출
	dr2.ShowDerivData();
	cout << "--------------------" << endl;

	cout << "case3....." << endl;
	SoDerived dr3(23, 24);	// SoBase(int n), SoDerived(int n1, int n2) 순으로 호출
	dr3.ShowDerivData();
	cout << "--------------------" << endl;
	return 0;
}