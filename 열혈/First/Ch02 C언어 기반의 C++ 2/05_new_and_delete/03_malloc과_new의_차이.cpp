/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : malloc과 new의 차이
	클래스를 생성할 때 new와 delete는 각각 생성자와 소멸자를 호출하고 알아서 포인터 형변환도 한다
	반면 malloc과 free는 생성자와 소멸자를 호출하지 못하고 인자 전달도 안된다

	malloc의 경우 realloc을 이용해 유동적으로 메모리를 관리 할 수 있다
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple {

	//접근 제한자 및 생성자
public :
	Simple() {

		cout << "I am simple constructor!" << endl;
	}
};

int main(void) 
{

	cout << "case 1 : ";
	Simple* sp1 = new Simple;	// 생성자 호출

	cout << "case 2 : ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);	// 생성자 호출 X

	cout << endl << "end of main" << endl;

	delete sp1;
	free(sp2);
	return 0;
}