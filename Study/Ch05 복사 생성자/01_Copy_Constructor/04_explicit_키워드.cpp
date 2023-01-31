/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : explicit 키워드
	변환에 의한 초기화를 막는 키워드

	코드의 명확함을 더하기 위해서 자주 사용되는 키워드
*/

class SoSimple {

private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) { }

	// 인자 안의 const는 copy의 내부 값 변형을 막기 위해 넣었다
	explicit SoSimple(const SoSimple& copy)	
		: num1(copy.num1), num2(copy.num2) { }
};

class A {

private:
	int num;

public:
	explicit A(int n) 
		: num(n) { }
};

int main(void)
{

	SoSimple sim1(2, 3);
	// SoSimple sim2 = sim1; // 에러
	SoSimple sim2(sim1);

	// A obj = 3; // 이처럼 생성하는 것을 막기 위해서도 사용
	A obj(3);
}