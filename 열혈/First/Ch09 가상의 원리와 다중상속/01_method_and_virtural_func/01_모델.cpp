/*
날짜 : 2023. 2. 10
이름 : 배성훈
내용 : 객체의 멤버함수와 멤버변수의 구성
	모델이 될 객체
*/

#include <iostream>
using namespace std;

class Data {

private:
	int data;
public:
	Data(int num)
		: data(num) { }

	void ShowData() {

		cout << "Data: " << data << endl;
	}

	void Add(int num) {

		data += num;
	}
};

int main(void)
{

	Data obj(15);
	obj.Add(17);
	obj.ShowData();		// Data: 32
	return 0;
}