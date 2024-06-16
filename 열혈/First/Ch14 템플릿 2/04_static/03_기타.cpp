/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 템플릿
	template <typename T> 와 tempalte <> 차이점

	template <typename T> 의 경우 T에 대한 정보가 필요한 경우 사용
	template <>는 정보가 필요없는 경우 사용
*/

#include <iostream>
using namespace std;


template<typename T>
class SoSimple {

private:
	static int mem;

public:
	void SimpleFunc() {

		cout << mem << endl;
	}
};



template<>
class SoSimple<int> {

private:
	static int mem;

public:
	void SimpleFunc() {

		cout << mem << endl;
	}
};


template<typename T>
int SoSimple<T>::mem = 0;
int SoSimple<int>::mem = 1;			// 바로 밑에 정의해야지 컴파일 에러가 안뜬다

template<>
// int SoSimple<int>::mem = 1;		// 명시적으로 특수활 할 수 없다고 컴파일 에러뜬다
int SoSimple<double>::mem = 2;

int main(void) {

	SoSimple<short> obj1;
	SoSimple<int> obj2;
	SoSimple<double> obj3;

	obj1.SimpleFunc();	// 0
	obj2.SimpleFunc();	// 1
	obj3.SimpleFunc();	// 2
	return 0;
}