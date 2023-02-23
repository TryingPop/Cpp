/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 클래스 템플릿과 static
	클래스 템플릿에서 static 멤버변수는
	템플릿 클래스마다 1개씩 존재한다
*/

#include<iostream>
using namespace std;

template<typename T>
class SimpleStaticMem {

private:
	static T mem;

public:
	void AddMem(T num) {

		mem += num;
	}
	void ShowMem() const {

		cout << mem << endl;
	}
};

template<typename T>
T SimpleStaticMem<T>::mem = 0;	// static 변수의 초기화 문장!

int main(void)
{

	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;

	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();	// 5

	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();	// 100
	return 0;
}