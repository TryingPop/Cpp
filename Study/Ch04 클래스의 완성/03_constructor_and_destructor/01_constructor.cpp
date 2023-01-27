/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자
	객체생성 과정에서 자동으로 호출되는 생성자에게 전달할 인자의 정보를 다음과 같이 추가
	클래스명 변수(생성자 인자);						// 전역, 지역 및 매개변수의 형태
	클래스명 * ptr = new 클래스명(생성자 인자);		// 동적 할당의 형태
	
	생성자
		클래스의 이름과 함수의 이름이 동일하다
		반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다

	생성자의 특징
		생성자도 함수의 일종이니 오버로딩이 가능하다
		생성자도 함수의 일종이니 매개변수에 '디폴트 값'을 설정할 수 있다
*/

#include <iostream>
using namespace std;

class SimpleClass {

private:
	int num1;
	int num2;

public:
	SimpleClass() {

		num1 = 0;
		num2 = 0;
	}

	SimpleClass(int n) {

		num1 = n;
		num2 = 0;
	}

	SimpleClass(int n1, int n2) {

		num1 = n1;
		num2 = n2;
	}

	/*
	SimpleClass(int n1 = 0, int n2 = 0) {

		num1 = n1;
		num2 = n2'
	}
	*/

	void ShowData() const {

		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{

	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();
	return 0;
}