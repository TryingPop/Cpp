/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : friend 키워드
	클래스 A, B 가 존재
	A 내부에 friend class B가 선언되어져 있으면
	B 에서 A의 private 멤버 변수에 접근이 가능하다
	반면 A에서 B 내부의 private 변수는 접근 안된다

	private, public 어디서 선언해도 상관없다

	friend 선언은 '정보은닉'을 무너뜨리는 문법이라
	필요한 구간에만 사용하는게 좋다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Girl;		// Girl 이라는 이름이 클래스의 이름임을 알림

class Boy {

private:
	int height;
	friend class Girl;	// Girl 클래스에 대한 friend 선언

public:
	Boy(int len)
		: height(len) { }

	void ShowYourFriendInfo(Girl& frn);
};

class Girl {

private:
	char phNum[20];

public:
	Girl(const char* num) {

		strcpy(phNum, num);
	}

	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;	// Boy 클래스에 대한 friend 선언
};

void Boy::ShowYourFriendInfo(Girl& frn) {

	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn) {

	cout << "His height: " << frn.height << endl;
}

int main(void)
{

	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}