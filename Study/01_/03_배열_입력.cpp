#include <iostream>		
using namespace std;	

/*

날짜 : 2023. 1. 21
이름 : 배성훈
내용 : 배열 입력
	iostream 해더의
	std::cin 배열 입력관리
*/

int main()
{

	// 담을 변수 동적 선언
	char name[100], lang[100];


	cout << "이름을 입력해주세요 : ";
	cin >> name;

	cout << "좋아하는 언어를 입력해주세요 : ";
	cin >> lang;
		

	//입력한 문자를 보여준다
	cout << "입력하신 숫자는 " << name << "입니다.\n";
	cout << "입력하신 숫자는 " << lang << "입니다." << endl;
}
