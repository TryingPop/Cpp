/*
날짜 : 2024. 8. 18
이름 : 배성훈
내용 : SoSimple sim2(sim1)
	교재 p 216 ~ 218

	내용에 적힌 SoSimple sim2(sim1)을 관찰하자
	그리고 생성자의 호출관점에서 이를 재분서갷보자

	SoSimple sim2(sim1);
	이 문장이 담겨있는 내용을 정리하면 다음과 같다

	SoSimple형 객체를 생성해라
	객체의 이름은 sim2로 정한다
	sim1을 인자로 받을 수 있는 생성자의 호출을 통해서 객체생성을 완료한다

	위의 내용과 관련해서는 추가적인 설명은 필요 없을 것이다
	즉 위의 객체생성문에서 호출하고자 하는 생성자는 
	다음과 같이 SoSimple 객체를 인자로 받을 수 있는 생성자이다

	SoSimple(SoSimple& _copy)
	{

		...
	}

	그리고다음의 문장도,
	SoSimple sim2 =sim1;

	실은 다음의 형태로 묵시적 변환이 되어서(자동적으로 변환이 되어서) 객체가 생성되는 것이다

	SoSimple sim2(sim1);

	그런데 앞서 정의한 SoSimple 클래스에는 이러한 유형의 생성자가 정의되어 있지 않았다
	이는 디폴트 복사 생성자에 대한 이해를 통해서 답을 내릴 수 있다
*/

#include <iostream>

using namespace std;

class SoSimple 
{

private:
	int num1;
	int num2;

public:
	SoSimple(int _n1, int _n2)
		: num1(_n1), num2(_n2) { }

	// 복사 생성자(copy constructor)
	// 멤버 대 멤버의 복사에 사용되는 원본을 변경시키는 것은
	// 복사의 개념을 무너뜨리는 행위가 되니
	// 키워드 const를 삽입해서 이러한 실수를 막는게 좋다
	// SoSimple(const SoSimple& _copy)
	SoSimple(SoSimple& _copy)
		: num1(_copy.num1), num2(_copy.num2) 
	{ 
	
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShoSimpleData()
	{

		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{

	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;		// SoSimple sim2(sim1);으로 변환
								// Called SoSimple(SoSimple &copy) 가 출력된다
	cout << "생성 및 초기화 직후" << endl;

	sim2.ShoSimpleData();

	return 0;
}