/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : const 객체의 오버로딩
	const 객체의 오버로딩 예시	
*/

#include<iostream>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n) 
		: num(n) { }

	SoSimple& AddNum(int n) {

		num += n;
		return *this;
	}

	void SimpleFunc() {

		cout << "SimpleFunc: " << num << endl;
	}
	

	void SimpleFunc() const {	// 위의 SimpleFunc를 오버로딩했다고 볼 수 있다

		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj) {

	obj.SimpleFunc();
}

int main(void)
{

	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();	// SimpleFunc ~~
	obj2.SimpleFunc();	// const SimpleFunc ~~

	YourFunc(obj1);		// const SimpleFunc ~~
	YourFunc(obj2);		// const SimpleFunc ~~
	return 0;
}