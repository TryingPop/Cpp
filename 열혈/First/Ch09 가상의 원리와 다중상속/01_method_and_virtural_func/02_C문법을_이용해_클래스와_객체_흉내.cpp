/*
날짜 : 2023. 2. 10
이름 : 배성훈
내용 : 객체의 멤버함수와 멤버변수의 구성
	구조체와 전역함수를 이용해 클래스와 객체를 흉내내서
	객체의 멤버함수와 멤버변수의 구성이 어떻게 이루어지는지 확인
*/

#include <iostream>
using namespace std;

// 클래스 Data를 흉내 낸 영역
typedef struct Data {

	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
};

void ShowData(Data* THIS) {

	cout << "Data: " << THIS->data << endl;
}

void Add(Data* THIS, int num) {

	THIS->data += num;
}

// 적절히 변경된 main함수
int main(void)
{

	// obj1, obj2 는 ShowData와 Add를 공유
	// 클래스도 동일하게 멤버변수는 객체 내에 존재
	// 멤버함수는 메모리의 한공간에 별도로 위치한다
	// 또, 이 함수가 정의된 클래스의 모든 객체가 이를 공유하는 형태
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
}