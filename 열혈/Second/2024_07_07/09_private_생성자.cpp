/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : private 생성자
	교재 p186 ~ 187

	앞서 보인 생성자들은 모두 public으로 선언되었다

	객체의 생성이 클래스의 외부에서 진행되면
	생성자는 public으로 선언되어야 한다

	클래스 내부에서 객체를 생성한다면,
	생성자가 private로 선언되어야 한다

	아래 예제를 보면,
	힙 영역에 생성된 객체를 참조의 형태로 반환하고 있다
	이는 힙에 랑당된 메모리 공간은 변수로 간주하여 참조자를 통한 참조가 가능하다
	라는 사실을 다시 한번 확인시켜 준다

	private로 선언된 생성자를 통해서도 객체의 생성이 가능함을 알 수 있다
	하지만 private 생성자도 때로는 유용하게 사용이 된다
	객체의 생성방법을 제한하고자 하는 경우에는 매우 유용하게 사용이 된다
*/

#include <iostream>

using namespace std;

class AAA
{

private:
	int num;

public:
	AAA() : num(0) { }
	AAA& CreateInitObj(int n) const
	{

		AAA* ptr = new AAA(n);
		return *ptr;
	}

	void ShowNum() const { cout << num << endl; }

private:
	AAA(int n) : num(n) { }
};

int main(void)
{

	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;
}