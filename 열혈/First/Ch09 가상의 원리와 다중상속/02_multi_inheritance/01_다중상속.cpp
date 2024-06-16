/*
날짜 : 2023. 2. 10
이름 : 배성훈
내용 : 다중상속
	다중상속에 대한 극단적인 의견
		다중상속은 득보다 싫이 많은 문법이다.

	다중상속에 대한 부드러운 의견
		일반적인 경우에서 다중상속은 다양한 문제를 동반한다
		따라서 가급적 사용하지 않아야 하나
		예외적으로 매우 제한적인 사용까지 부정할 필요는 없다
*/

#include <iostream>
using namespace std;

class BaseOne {

public:
	void SimpleFuncOne() {

		cout << "BaseOne" << endl;
	}
};

class BaseTwo {

public:
	void SimpleFuncTwo() {

		cout << "BaseTwo" << endl;
	}
};

class MultiDerived : public BaseOne, protected BaseTwo {

public:
	void ComplexFunc() {

		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main(void)
{

	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}