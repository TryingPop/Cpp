/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : 캡슐화의 정확한 이해
	교재 p163 ~ 166

	앞의 예제를 캡슐화한 예제이다
	결과는 이전 예제와 동일하다

	캡슐화를 할 때 하나의 클래스로만 모든 것을 구성해야 하는 것이 아니다
	다른 클래스를 활용해도 된다
	문제는 어떻게 구성을 하느냐가 아니고,
	어떠한 내용으로 구성하는가이다

	관련있는 변수와 함수를 하나의 클래스 안에 묶는 것이 캡슐화이다
	캡슐화는 어려운 개념이다 캡슐화의 범위를 결정하는 일이 쉽지 않기 때문이다

	캡슐화는 감싸는 개념이다
	그런데 감싸려면 안전하게 감싸야한다
	멤버변수가 보이지 않게 정보를 은닉해서 감싸면 좋다
	캡슐화는 기본적으로 정보은닉을 포함하는 개념이다

	경험많은 객체지향 프로그래머를 구분하는데 첫 번째 기준은 캡슐화이다
	캡슐화는 일관되게 적용할 수 있는 단순한 개념이 아니고,
	구현하는 프로그램의 성격과 특성에 따라서
	적용하는 범위가 달라지므로 정답이 없는 개념이기 때문이다
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

class CONTAC600
{

private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{

		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient
{

public:
	void TakeCONTAC600(const CONTAC600& cap) const
	{

		cap.Take();
	}
};

int main(void)
{

	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}