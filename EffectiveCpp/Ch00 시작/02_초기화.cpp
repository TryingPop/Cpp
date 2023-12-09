/*
날짜 : 2023. 12. 09
이름 : 배성훈
내용 : 초기화
	교재 43 ~ 45p
*/

// 초기화 - 사용자 정의 타입으로 생성한 객체의 경우, 초기화는 생성자에 의해 이루어진다.
// 기본 생성자(default constructor)는 어떤 인자도 주어지지 않은 채로 호출될 수 있는 생성자
// 원래부터 매개변수가 없거나 모든 매개변수가 기본 값을 갖고 있으면 기본 생성자가 될 수 있다
class A {

public:

	A();										// 기본 생성자
};

class B {

public:

	explicit B(int x = 0, bool b = true);		// 기본 생성자
												// explicit은 암시적인 타입 변환을 수행하는 데 쓰이지 않는다
												// 타입 변환이 명시적인 곳에서는 사용 가능
												// explicit 선언은 프로그래머가 예상하지도 못했던 타입 변환을 막아준다
};

class C {

public:

	explicit C(int x);							// 기본 생성자가 아니다
};

void doSomething(B bObject);					// B 타입의 객체를 하나 받는 함수


// 교재에는 main 함수 없이 모두가 안에 있는데, 
// 여기서 그대로 따라 하면 
// doSomething(bObj1);
// 에서 컴파일 에러뜬다 그래서 main으로 대체
void main() {

	B bObj1;									// B 타입의 객체
	doSomething(bObj1);							// 문제 없다

	B bObj2(28);								// 문제 없다 int 인자 28로 B 하나를 만든다
												// bool b 는 자동으로 true 가 들어간다

	// doSomething(28);							// 에러 
												// 그냥 int가 들어가면 안된다 게다가 int에서 B로 바뀌는 암시적인 변환이 없다

	doSomething(B(28));							// 지금의 호출에서는 B 클래스의 생성자를 써서 int에서 B로 명시적으로 변환
												// 즉, 캐스팅 합니다.
}

void doSomething(B bObject) { return; }			// 정의