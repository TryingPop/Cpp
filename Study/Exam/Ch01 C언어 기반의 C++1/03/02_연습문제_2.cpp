#include <iostream>
using namespace std;

/*

날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 32p 문제2
	다음과 같은 형태로의 함수 오버로딩은 문제가 있다.
	어떠한 문제가 있는지 설명해 보자.
*/


int SimpleFunc(int a = 10) {

	return a + 1;
}

int SimpleFunc() {

	return 10;
}

int main()
{

//	SimpleFunc(); // 다음과 같이 불러 올 때 호출이 모호하다는 에러 메세지가 뜬다
				  // C# 의 경우는 가까운 것을 불러온다고 되어져 있고
				  // 같은 클래스 안에서 오버로드 되어져 있는 경우 인자가 없는 SimpleFunc() 가 호출된다
	return 0;
}