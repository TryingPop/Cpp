/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 유도 클래스 객체의 소멸과정
	생성자 호출 과정처럼 소멸자도 호출될 것이다

	유도 클래스의 소멸자 > 자식 클래스의 소멸자 순으로 호출된다
*/

#include <iostream>
using namespace std;

class SoBase {

private:
	int baseNum;

public:
	SoBase(int n)
		: baseNum(n) {

		cout << "SoBase() : " << baseNum << endl;
	}

	~SoBase() {

		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived : public SoBase {

private:
	int derivNum;

public:
	SoDerived(int n)
		: SoBase(n), derivNum(n) {

		cout << "SoDerived() : " << derivNum << endl;
	}

	~SoDerived() {

		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{

	SoDerived drv1(15);
	SoDerived drv2(27);
	return 0;
}