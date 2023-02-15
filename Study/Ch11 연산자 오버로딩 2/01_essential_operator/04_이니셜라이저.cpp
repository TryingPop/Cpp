/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 이니셜라이저
	이니셜라이저를 사용하면 성능이 향상되는 이유

	이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성된다

	생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면,
	선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드가 생성된다

	그래서 이니셜라이저를 이용해서 초기화를 진행하면,
	함수의 호출횟수를 줄일 수 있어서
	그리고 초기화의 과정을 단순화 시킬 수 있어서 약간의 성능향상을 기대할 수 있다
*/

#include <iostream>
using namespace std;

class AAA {

private:
	int num;

public:
	AAA(int n = 0)
		: num(n) { 

		cout << "AAA(int n = 0)" << endl;
	}

	AAA(const  AAA& ref)
		: num(ref.num) { 

		cout << "AAA(const AAA& ref)" << endl;
	}

	AAA& operator=(const AAA& ref) {

		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB {

private:
	AAA mem;

public:
	BBB(const AAA& ref) 
		: mem(ref) { }
};

class CCC {

private:
	AAA mem;

public:
	CCC(const AAA& ref) {

		mem = ref;
	}
};

int main(void)
{

	AAA obj1(12);	// AAA(int n = 0)
	cout << "*********************" << endl;

	BBB obj2(obj1);	// AAA(const AAA& ref)
					// 복사 생성자만 호출
	cout << "*********************" << endl;

	CCC obj3(obj1);	// AAA(int n = 0)
					// operator=(const AAA& ref)
	return 0;
}