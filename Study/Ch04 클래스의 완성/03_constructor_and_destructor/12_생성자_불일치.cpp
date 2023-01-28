/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자 불일치
	매개변수가 void형으로 선언되는 디폴트 생성자는,
	생성자가 하나도 정의되어 있지 않을 때에만 삽입된다
*/

class SoSimple {

private:
	int num;

public:
	SoSimple(int n) :num(n){ }
	// SoSimple(int n = 0) : num(n){ }
};

int main(void) 
{

	SoSimple simObj1(10);
	SoSimple* simPtr1 = new SoSimple(2);

	// 생성자가 있으므로 아래 방법으로 정의 불가
	// 다만 초기값 선언해주면 사용 가능
	// SoSimple simObj2;
	// SoSimple* simPtr2 = new SoSimple;


}