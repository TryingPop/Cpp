/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 세가지 형태의 상속
	public 상속
		public 보다 접근의 범위가 넓은 멤버는 public으로 변경시켜 상속하겠다
		private를 제외한 나머지는 그냥 그대로 상속한다는 말과 동치
*/

class Base {

private:
	int num1;

protected:
	int num2;

public:
	int num3;
};

class Derived : public Base { };	// C#에서 상속과 같다