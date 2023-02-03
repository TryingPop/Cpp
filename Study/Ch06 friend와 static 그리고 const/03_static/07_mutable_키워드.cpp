/*
날짜 : 2023. 2. 3
이름 : 배성훈
내용 : mutable 키워드
	const와 explicit 키워드는 나름 의미가 있으며, 또 유용하게 사용되는 키워드
	반면 mutable은 가급적 사용의 빈도수를 낮춰야 하는 키워드

	const 함수 내에서의 값의 변경을 예외적으로 허용하는 키워드
*/

#include <iostream>
using namespace std;

class SoSimple {
	
private:
	int num1;
	mutable int num2;	// const 함수에 대해 예외를 둔다

public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2) { }

	void ShowSimpleData() const {

		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() {

		num2 = num1;
		// mutable이 num1 = num2를 방지한다는 면에서는 좋을 수 있다
	}
};

int main(void)
{

	SoSimple sm(1, 2);
	sm.ShowSimpleData();	// 1, 2
	sm.CopyToNum2();
	sm.ShowSimpleData();	// 1, 1
	return 0;
}