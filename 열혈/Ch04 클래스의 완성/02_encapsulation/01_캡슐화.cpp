/*
날짜 : 2023. 1. 27
이름 : 배성훈
내용 : 캡슐화의 필요성
	캡슐화가 무너지면 클래스 상호관계가 복잡해진다
	그래서 프로그램 전체의 복잡도를 높이는 결과로 이어진다
*/
#include <iostream>
using namespace std;

class SinivelCap {	// 콧물 처치용 캡슐

public:
	void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap {	// 재채기 처치용 캡슐

public:
	void Take() const { cout << "재채기가 맞습니다." << endl; }
};

class SnuffleCap {	// 코막힘 처치용 캡슐

public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class ColdPatient {

public:
	void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
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