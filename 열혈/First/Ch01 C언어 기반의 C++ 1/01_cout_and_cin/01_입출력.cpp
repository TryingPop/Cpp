#include <iostream>		// 기본 입출력 시스템을 담은 헤더
using namespace std;	// cin, cout을 간단하게 치기위해 앞에 선언

/*

날짜 : 2023. 1. 21
이름 : 배성훈
내용 : 입출력
	iostream 해더의
	std::cin 입력관리 
	std::cout 출력관리
*/

int main()
{

	// 담을 변수 동적 선언
	string inputStr;

	// 문자 출력
	cout << "원하는 문자를 입력해주세요 : ";

	// 입력 받은 문자열을 inputStr에 입력
	// 현재 string으로 입력받고 넣기에 이상없이 들어간다
	cin >> inputStr;

	//입력한 문자를 보여준다
	cout << "입력하신 문자는 " << inputStr << "입니다.";
}
