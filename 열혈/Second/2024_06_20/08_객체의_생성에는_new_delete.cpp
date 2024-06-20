/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : 객체의 생성에서는 반드시 new & delete
	교재 p93 ~ 95

	new와 malloc 함수의 동작방식에는 차이가 있다
	malloc은 그냥 메모리 공간만 할당할 뿐이다
	new의 경우 메모리 공간 할당과 생성자 함수가 실행된어 값을 초기화할 수 있다
	이는 추후에 다시 다룬다
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Simple
{

public:
	Simple()
	{

		cout << "I am simple constructor!" << endl;
	}
};

int main(void)
{

	cout << "case 1: ";
	Simple* sp1 = new Simple;

	cout << "case 2: ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	return 0;
}