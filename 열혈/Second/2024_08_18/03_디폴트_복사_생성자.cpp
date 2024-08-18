/*
날짜 : 2024. 8. 18
이름 : 배성훈
내용 : 디폴트 복사 생성자와 키워드 explicit
	교재 p218 ~ 221

	복사 생성자를 정의하지 않으면, 멤버 대 멤버의 복사를 진행하는
	디폴트 복사 생성자가 자동으로 삽입된다

	많은 경우에 있어서 복사 생성자를 직접 정의하지 않아도 된다
	그러나 반드시 복사 생성자를 정의해야 하는 경우도 있다

	변환에 의한 초기화는 키워드 explicit으로 막을 수 있다
	SoSimple sim2 = sim1;
	는 다음의 형태로 묵시적 변환이 일어나서 복사 생성자가 호출된다
	SoSimple sim2(sim1);

	만약 위처럼의 변환이 맘에 들지 않는다면
	복사 생성자의 묵시적 호출을 허용하지 않으면 된다
	이러한 목적으로 사용되는 키워드가 explicit이다

	그리고 묵시적 변환은 복사 생성자에서만 일어나는 게 아니다
	전달인자가 하나인 생성자에 대해서도 묵시적 변환이 발생한다

	복사생성자의 매개변수는 참조형 선언을 의미하는 &는 단드시 삽입해야 한다
	& 선언이 없다면 복사 생성자의 호출은 무한루프에 빠진다
	C++ 컴파일러는 & 선언을 하지 않으면 컴파일 에러를 발생시켜 주기에 
	실제로 무한루프에 빠지는 일은 없다
*/

class SoSimple
{

private:
	int num1;
	int num2;

public:
	SoSimple(int _n1, int _n2)
		: num1(_n1), num2(_n2) { }

	SoSimple(int _n1) 
		: num1(_n1), num2(0) { }

	explicit SoSimple(const SoSimple& _copy)
		: num1(_copy.num1), num2(_copy.num2) { }
};

int main(void)
{

	SoSimple sim1(15, 30);
	
	// SoSimple sim2 = sim1;	// 복사 생성자가 없다는 컴파일 에러 발생
	SoSimple sim2(sim1);

	// SoSimple sim3(3); 
	SoSimple sim3 = 3;	// 위와 같다	

	return 0;
}