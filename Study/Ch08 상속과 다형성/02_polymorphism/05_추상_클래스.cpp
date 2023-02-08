/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 순수 가상함수와 추상 클래스
	클래스 중에서 객체생성을 목적으로 정의되지 않는 클래스도 존재한다

	pure virtual function
		함수의 몸체가 정의되지 않는 함수
		const에 const = 0 을 줌으로써 컴파일러에게 명시적으로 몸체를 정의하지 않았다고 알려준다

	abstract 클래스
		하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스
*/

class AbsClass {

private:
	int num;

public:
	AbsClass() { }

	void Func1() { }
	virtual void Func2() const { }
	virtual void PureFunc() const = 0 { }	// 추상 클래스 선언
};

int main(void)
{

	// 추상 클래스인 AbsClass를 호출하려 했기에 컴파일 에러가 뜬다
	// AbsClass abs1 = new AbsClass;
	// AbsClass abs2;
	return 0;
}