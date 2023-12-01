/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 형 변환 연산자
	객체를 기본 자료형 데이터로 형 변환하는 예제
*/

#include <iostream>
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

	// int  형으로 현 변환 해야하는 상황에서 호출하는 함수
	operator int() {	// 형 변환 연산자의 오버로딩

		return num;
	}
	
	void ShowNumber() {

		cout << num << endl;
	}
};

int main(void)
{

	Number num1;				
	num1 = 30;					// Number(int n = 0)

	Number num2 = num1 + 20;	// Number(int n = 0)
								// operator=()
								// operator int 가 없으면 컴파일 에러

	num2.ShowNumber();			// 50
	return 0;
}