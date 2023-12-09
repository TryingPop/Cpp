/*
날짜 : 2023. 12. 09
이름 : 배성훈
내용 : 나머지
	교재 46 ~ 50p

	STL은 표준 템플릿 라이브러리(Standard Template Library) 의 준말
	C++ 표준 라이브러리에 속해 있는 라이브러리 인데 컨테이너(vector, list, set, map 등), 
	반복자(vector<int>::iterator, set<string>::iterator 등),
	알고리즘(for_each, find, sort 등) 및 이들과 관련된 기능들이 집결한 결정체

	함수 객체(function object), 즉 함수처럼 동작하는 C++ 객체가 차지하고 있다

	인터페이스(interface) C++에는 그런 게 없다
	여기서 인터페이스는 설계 아이디어로서의 인터페이스!

	사용자(client)는 사용하는 아무개
*/

#include <iostream>
// 미정의 동작(undefined behavior) 
// 저급 언어라 무엇이 나올지 모른다 
// 미정의 동작은 위험해서 미정의 동작이 안되게 코드 설계 하는 것이 중요하다!
int* p = 0;					// null 포인터

void main() {

	std::cout << *p;		// 널포인터를 역참조하면
							// 미정의 동작이 발생

	char name[] = "Darla";	// name의 크기가 6 (끝에 붙은 널 문자를 놓치면 낭패!)인 배열

	char c = name[10];		// 유효하지 않은 배열 원소지정번호(index)로 
							// 참조하려 하면 미정의 동작이 발생
							// 무엇이 나올지 모른다
							// 열혈에서 인덱스 에러 뜨게 코드 작성했었다!
}