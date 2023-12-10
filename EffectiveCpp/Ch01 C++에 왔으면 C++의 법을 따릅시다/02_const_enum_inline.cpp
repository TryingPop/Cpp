/*
날짜 : 2023. 12. 10
이름 : 배성훈
내용 : #define을 쓰려거든 const, enum, inline을 떠올리자
	교재 53 ~ 58p

	선행 처리자(전처리기)보다 컴파일러를 더 가까이 하자는 제목

	#define은 클래스 상수를 정의하는 데 쓸 수도 없을 뿐만 아니라 어떤 형태의 캡슐화 혜택도 받을 수 없다
	private 성격의 #define 같은 것은 없다는 이야기

	단순한 상수를 쓸 대는, #define 보다는 const 객체 혹은 enum을 우선 생각
	함수처럼 쓰이는 매크로를 만들러면, #define 매크로보다 인라인 함수를 우선 생각
*/


// 해당 매크로를 정의 했다고 가정
// 프로그래머한테는 ASPECT_RATIO가 기호식 이름(symbolic name)으로 보이지만 
// 컴파일러에게는 전혀 보이지 않는다
// 소스 코드가 어떻게든 컴파일러에게 넘어가기 전에 선행 처리자가 밀어버리고 숫자 상수로 바꾸어 버리기 때문이다
// 그래서 ASPECT_RATIO 라는 이름은 컴파일러가 쓰는 기호 테이블에 들어가지 않고
// 에러 메세지엔 1.653이 뜬다
#define ASPECT_RATIO 1.653


// #define의 오용 사례는 매크로 함수
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

#include<iostream>

// 그래서 해당 문제의 해결법은 상수를 쓴다
// 그러면 기호 테이블에도 들어가고 부동 소수점 실수 타입일 경우에는 
// 컴파일을 거친 최종 코드의 크기가 #define을 썼을 때 보다 작게 나올 수 있다
// 실제로 매크로를 쓰면 코드에 ASPECT_RATIO가 등장하기만 하면 선행 처리자에 의해 1.653으로 모두 바뀌면서 
// 목적 코드 안에 1.653의 사본이 등장 횟수만큼 들어가게 되지만,
// 상수 타입의 AspectRatio는 여러 번 쓰이더라도 사본은 딱 한 개만 들어가기 때문
const double AspectRatio = 1.653;		// 대문자로 표기하는 이름은 대게 매크로에서 쓰는 것이어서,
										// 이름 표기도 바꾼다


// #define을 상수로 교체할 때는 딱 두 가지 경우만 조심해야 한다

// 상수 포인터(constant pointer)를 정의하는 경우
// 상수 정의는 대게 헤더 파일에 넣는 것이 상례 포인터는 꼭 const로 선언
// 대상까지 const로 선언하는 것이 보통
// 문자열 상수를 쓸 때는 string 객체가 대체적으로 사용하기 괜찮다
const std::string authorName("Scott Meyers");

// 두 번째는클래스 멤버로 상수를 정의하는 경우
// 사본 개수가 한개를 넘지 못하게 하고 싶다면 정적(static) 멤버로 만들어야 한다

class GamePlayer {

private:

	static const int NumTurns = 5;		// 상수 선언
										// 정의된 것이 아니다
										// C++ 에서는 사용하고자 하는 것에 대해 정의가 마련되어야 하는 게 보통이지만,
										// 정적 멤버로 만들어지는 정수류 타입의 클래스 내부 상수는 예외
										// 주소를 취하지 않는 한, 정의 없이 선언만 해도 아무 문제가 없다
										// 단 클래스 상수의 주소를 구한다든지, 
										// 컴파일러가 잘못 만들어진 관계로 정의를 달라고 떼쓰는 경우에는 별도로 정의를 제공해야 한다

	// 위와 같이 값을 넣는게 안되는 경우
	// enum { NumTurns = 5 };				// 해당 코드를 정의! << 나열자 둔갑술?
										// 그러면 scores의 NumTurns이 enum의 색깔로 바뀐다
										// 동작 방식이 #define과 비슷하다
										// 즉, 주소 잡기가 안된다
										// 그런데 #define 처럼 쓸데없는 메모리할당을 하지 않는다
										// 템플릿 메타 프로그래밍의 핵심 기법이다

	int scores[NumTurns];				// 상수를 사용하는 부분
};


const int GamePlayer::NumTurns;			// NumTurns의 정의
										// 값을 별도로 주지 않아도 된다
										// 클래스 상수의 초기값은 해당 상수가 선언된 시점에 바로 주어지기 때문에 여기서 값을 줄 필요가 없다


class CostEstimate {

private:

	static const double FudgeFactor;	// 조금 오래된 컴파일러에서는 선언과 동시에 값을 넣을 수 없는 경우도 있다
										// 해당 경우 선언만 하고 아래서 정의해야한다!
};
										

const double 
	CostEstimate::FudgeFactor = 1.35;	// 웬만한 경우는 이러한	방법으로 해결된다
										// 다만 GamePlayer 같이 배열의 크기로 상수를 사용하는 경우
										// 즉, 컴파일하는 도중 클래스 상수의 값이 필요할 때에
										// 나열자 둔갑술(enum hack)이라는 알려진 기법을 생각할 수 있다


/*
int main() {

	int a = 5, b = 0;
	// CALL_WITH_MAX(++a, b);			// a가 두 번 증가한다
	// CALL_WITH_MAX(++a, b + 10);		// a가 한 번 증가한다

	return 0;
}
*/

template<typename T>					// T가 정확하게 무엇인지 모르기에 매개변수로 상수 객체에 대한 참조자를 쓴다
inline void callWithMax(const T& a, const T& b) {

	f(a > b ? a : b);
}