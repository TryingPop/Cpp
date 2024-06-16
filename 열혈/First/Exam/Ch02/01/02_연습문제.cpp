/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : 교재 80p 문제2
	앞서 소개한 예제 RefSwap.cpp의 SwapByRef2 함수를
	다음의 형태로 호출하면 컴파일 에러가 발생한다.

	SwapByRef2(23, 45);

	컴파일 에러가 발생하는 이유가 무엇인지 설명해보자

	SwapByRef2함수의 정의
	void SwapByRef2(int& ref1, int &ref2){

		int temp = ref1;
		ref1 = ref2;
		ref2 = temp;
	}
*/

// 에러가 뜨는 이유는 참조자가 상수를 참조할 수 없기 때문이다
void SwapByRef2(int& ref1, int& ref2) {

	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}


int main(void)
{

	// SwapByRef2(23, 45); //에러 : 비const 참조에 대한 초기 값은 lvalue여야 한다.
}