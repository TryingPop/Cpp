/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 복사 생성자의 초기화
	객체를 반환하되, 참조형으로 반환하지 않는 경우
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n) 
		: num(n) { }

	SoSimple(const SoSimple& copy)
		: num(copy.num) {

		cout << "Called by SoSimple(const SoSimple& copy)" << endl;
	}

	SoSimple& AddNum(int n) {

		num += n;
		return *this;
	}

	void ShowData() {

		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {

	cout << "retrun 이전" << endl;
	return ob;
}

int main(void) 
{

	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();	// SimpleFuncObj 의 인자 ob 복사 참조에서 호출 1번
												// SimpleFuncObj 반환에서 복사 참조 호출 1번
												// 반환 시에 임시 객체가 생성된다
	obj.ShowData();
	return 0;
}