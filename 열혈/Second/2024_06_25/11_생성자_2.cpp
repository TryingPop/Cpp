/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : 생성자 
	교재 p171 ~ 173

	new 키워드를 이용한 객체의 생성에서는
	매개변수가 없는 경우 소괄호를 써도되고 안써도 된다
	(class 이름)* (변수 이름) = new (class 이름);
	(class 이름)* (변수 이름) = new (class 이름)();

	둘 다 허용한다
	MyClass* myClass = new MyClass;
	MyClass* myClass = new MyClass();
	둘 다 가능하다

	(class 이름) (변수명)()이 안되는 이유는 아래 예제에서 확인할 수 있다
	보통 함수의 원형 선언은 전역적으로 선언하지만지역적으로도 선언 가능하다
	아래의 Simple sc1()은 함수의 원형 선언에 해당한다
	void형 생성자의 호출문으로 인정해버리면, 컴파일러는 이러한 문장을 만났을 때,
	객체생성문인지 함수의 원형선언인지를 구분할 수 없게 된다

	그래서 (클래스 이름) (변수 이름)() 문장은 객체생성이 아닌,
	함수의 원형선언에만 사용된다
*/

#include <iostream>
using namespace std;

class SimpleClass
{

private:
	int num1;
	int num2;

public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{

		num1 = n1;
		num2 = n2;
	}

	void ShowData() const
	{

		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{

	SimpleClass sc1();			// 함수의 원형 선언
	SimpleClass mysc = sc1();
	mysc.ShowData();
	return 0;
}

SimpleClass sc1()
{

	SimpleClass sc(20, 30);
	return sc;
}