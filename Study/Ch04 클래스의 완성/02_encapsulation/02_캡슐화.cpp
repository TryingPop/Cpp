/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : 캡슐화
	관련 있는 함수와 변수를 하나의 클래스 안에 묶는 것이 캡슐화
	캡슐화의 범위를 결정하는 일이 쉽지 않다

	상황따라 아래의 캡슐화가 좋을 수도 안좋을 수도 있다
	그래서 상황에 맞춰서 캡슐화를 하면 된다

	캡슐화는 정보를 안전하게 감싸기 위해서 정보은닉을 해서 감싸는 것이 좋다
*/

#include <iostream>
using namespace std;

class SinivelCap {

public:
	void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap {

public:
	void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class SnuffleCap {

public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class CONTAC600 {

private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const {

		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient {

public:
	void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
};

int main(void) 
{

	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}