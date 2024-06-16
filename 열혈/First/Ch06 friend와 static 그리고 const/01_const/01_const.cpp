/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : const 객체
	const 선언이 갖는 의미는 이 객체의 데이터 변경을 허용하지 않겠다
*/

#include<iostream>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n)
		:num(n) { }

	SoSimple& AddNum(int n) {

		num += n;
		return *this;
	}

	void ShowData() const {
		cout << "num : " << num << endl;
 	}
};

int main(void)
{

	const SoSimple obj(7);
	// obj.AddNum(20);	// const 선언되어서 const 메소드만 호출 가능하다
	obj.ShowData();
	return 0;
}