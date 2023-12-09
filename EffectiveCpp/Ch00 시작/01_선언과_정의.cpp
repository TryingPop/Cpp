/*
날짜 : 2023. 12. 01
이름 : 배성훈
내용 : 선언과 정의
	교재 : 39 ~ 43p
	
	이 책의 목적은 C++를 효과적으로 구사하는 방법을 가르쳐 주는 것
	즉, C++ 라는 언어를 사용해서 제작한 소프트웨어가 이해하기 좋고 유지보수에도 그만이고 
	이식성, 확장성, 효율성까지 지님은 물론이며 의도대로 동작하게 만들 때까지 
	많은 수고가 들지 않는 그런 결과물이 되는 데  도움이 될 지침 혹은 조언들을 모아둔 책
*/

#include <cstddef>									// size_t

// 선언 - 코드에 사용되는 어떤 대상의 이름과 타입을 컴파일러에게 알려 주는 것
extern int x;										// 객체 선언
													// 정수는 기본제공(built-in) 타입인데도 객체로 표현

std::size_t numDigits(int number);					// 함수 선언
													// size_t는 개수를 셀 때 이 타입을 이용
													// 비슷하게 char* 기반의 문자열 크기, STL 컨테이너의 원소 개수 등
													// vector, string의 operator[] 함수가 취하는 타입
													// operator[] 함수를 정의할 때도 size_t를 받도록 만드는게 규약
													// 모든 함수의 선언문에는 시그니처(signature), 함수의 매개변수 리스트와 반환 타입이 나와 있다

class Widget;										// 클래스 선언

template<typename T>								// 탬플릿 선언
class GraphNode;						

// 정의 - 선언에서 빠진 구체적인 세부사항을 컴파일러에게 제공
int x;												// 객체 정의

std::size_t numDigits(int number) {					// 함수 정의

	std::size_t digitsSoFar = 1;					// 이 함수의 반환 값은 매개변수에 들어 있는 숫자의 개수

	while ((number /= 10) != 0) ++digitsSoFar;
	return digitsSoFar;
}

class Widget {										// 클래스 정의

public:

	Widget();
	~Widget();
};

template<typename T>
class GraphNode {									// 템플릿 정의

public:

	GraphNode();
	~GraphNode();
};