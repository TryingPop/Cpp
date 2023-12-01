#include <iostream>		
using namespace std;

/*

날짜 : 2023. 1. 21
이름 : 배성훈
내용 : 교재 22p 문제2
	프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 
	입력 받은 데이터를 그대로 출력하는 프로그램을 작성해 보자.
*/

int main()
{

	// 변수 선언
	char name[100], cp[100];

	// 입력
	cout << "이름을 입력하세요 : ";
	cin >> name;

	cout << "전화번호를 입력하세요 : ";
	cin >> cp;

	// 결과 출력
	cout << name << "의 전화번호는 " << cp << "입니다.";
}
