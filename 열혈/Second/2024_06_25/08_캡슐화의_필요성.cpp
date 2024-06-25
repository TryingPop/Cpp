/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : 캡슐화
	교재 p161 ~ 163

	캡슐화와 정보은닉의 차이를 아는 것이 중요하다
	먼저 캡슐화가 성립되지 않은 예제를 보자

	하나의 목적하에 둘 이상의 기능이 모여서 하나의 목적을 달성하고 있다
	여기서 기능의 순서가 변경될 수 있고 순서 여부가 중요할 때,
	아래 예제는 매우 위험한 구조가 될 수 밖에 없다

	캡슐화가 무너지면 객체의 활용이 매우 어려워진다
	뿐만 아니라 캡슐화가 무너지면 클래스 상호관계가 복잡해지기 때문에 이는 프로그램 전체의 복잡도를 높이는 결과로 이어진다
*/

#include <iostream>

using namespace std;

class SinivelCap
{

public:
	void Take() const
	{

		cout << "콧물이 싹~ 납니다." << endl;
	}
};

class SneezeCap
{

public:
	void Take() const
	{

		cout << "재채기가 멎습니다." << endl;
	}
};

class SnuffleCap
{

public:
	void Take() const
	{

		cout << "코가 뻥 뚫립니다." << endl;
	}
};

class ColdPatient
{

public:
	void TakeSinivelCap(const SinivelCap& cap) const
	{

		cap.Take();
	}

	void TakeSneezeCap(const SneezeCap& cap) const
	{

		cap.Take();
	}

	void TakeSnuffleCap(const SnuffleCap& cap) const
	{

		cap.Take();
	}
};

int main(void)
{

	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;

	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);

	return 0;
}