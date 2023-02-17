/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 형 변환 연산자
	임시객체로의 자동 형 변환과 형 변환 연산자
*/

#include<iostream>
using namespace std;

class Number {

private:
	int num;

public:
	Number(int n = 0)
		: num(n) { 
	
		cout << "Number(int n = 0)" << endl;
	}

	Number& operator=(const Number& ref) {

		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	void showNumber() {

		cout << num << endl;
	}
};

int main(void)
{

	Number num;			// Number(int n = 0);

	num = 30;			// Number(int n = 0);
						// operator=()
						// 여기서 다음과 같은 순서로 실행된다
						// num = Number(30);
						// num.operator(Number(30))
						// A형 객체가 와야 할 위치에 B형 데이터(또는 객체)가 왔을 경우,
						// B형 데이터를 인자로 전달받는 Aㅁ형 클래스의 생성자 호출을 통해서
						// A형 임시객체를 생성한다

	num.showNumber();	// 30
	return 0;
}