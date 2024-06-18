/*
날짜 : 2024. 6. 18
이름 : 배성훈
내용 : C언어의 복습 (호출 형태)
	교재 p62 ~ 63

	함수의 호출형태는 크게 값에 의한 호출(Call by value)과
	참조에 의한 호출(Call by reference)로 나뉜다

	이 둘을 나누는 기준이 무엇인지, 두 int형 변수의 값을 교환하는
	Swap 함수를 예로 들어가면서 설명해보자

	Call by value는 해당 값을 그대로 전달하는 것이고,
	Call by reference는 변수가 가리키는 주소를 전달하는 것을 의미한다

	그래서 Call by value로 전달한 변수는
	값을 수정해도 기존 값에 영향을 끼치지 않는다

	반면 Call by reference로 전달한 변수는
	주소를 전달했기에 주소에 있는 값에 직접적으로 접근이 가능해진다
	이에 해당 주소의 값을 바꾸면 함수가 끝나도 변환된 채로 있는다
*/

#include <iostream>

#define endl '\n'
#define AND ", "
using namespace std;

void SwapValue(int _num1, int _num2)
{

	int temp = _num1;
	_num1 = _num2;
	_num2 = temp;
}

void SwapRef(int* _num1, int* _num2)
{

	int temp = *_num1;
	*_num1 = *_num2;
	*_num2 = temp;
}

int main(void)
{

	int num1 = 10, num2 = 20;

	cout << "Before ";
	cout << "num1, num2: " << num1 << AND << num2 << endl;	// 10 20

	// 매개변수 _num1, _num2의 값만 바뀐다
	// num1, num2는 바뀌지 않는다
	SwapValue(num1, num2);
	cout << "SwapValue ";
	cout << "num1, num2: " << num1 << AND << num2 << endl;	// 10 20

	// num1, num2 주소가 전달되어
	// 주소가 가리키는 값이 변경된다
	// 그래서 num1의 값과, num2가 가리키는 값이 뒤바뀐다
	SwapRef(&num1, &num2);
	cout << "SwapRef ";
	cout << "num1, num2: " << num1 << AND << num2 << endl;	// 20 10


	return 0;
}