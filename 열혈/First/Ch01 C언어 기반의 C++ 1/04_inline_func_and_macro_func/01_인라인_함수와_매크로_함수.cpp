#include <iostream>
// 매크로 함수
#define SQUARE(x) ((x) * (x))
using namespace std;

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 인라인 함수와 매크로 함수
	매크로 함수 : 일반 함수에 비해 속도가 빠르다 
			반면 복잡한 함수를 매크로의 형태로 정의하는데 한계가 있다
	인라인 함수 : 매크로 함수의 단점을 보완한 C++의 함수
	
	매크로 함수는 자료형에 상관없이 사용가능하다
	인라인 함수는 템플릿을 이용해 자료형 상관없이 이용 가능

	템플릿은 다음과 같이 이용 가능 추후에 다룬다
	template <typename T>
	inline  T Add(T num1, T num2) {

		return num1 + num2;
	}
*/

inline int Add(int num1, int num2) {

	return num1 + num2;
}




int main()
{
	cout << "매크로 함수 SQUARE(1) : " << SQUARE(1) << endl;
	cout << "인라인 함수 Add(1, 1) : " << Add(1, 1) << endl;

	return 0;
}