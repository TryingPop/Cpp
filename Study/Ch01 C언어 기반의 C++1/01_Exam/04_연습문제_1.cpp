#include <iostream>		
using namespace std;

/*

날짜 : 2023. 1. 21
이름 : 배성훈
내용 : 교재 22p 문제1
	사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해보자.
	단 프로그램의 실행은 다음과 같이 이루어져야 한다.

	실행의 예
	1번째 정수 입력 : 1
	2번째 성수 입력 : 2
	3번째 성수 입력 : 3
	4번째 성수 입력 : 4
	5번째 성수 입력 : 5
	합계 : 15
*/

int main()
{
	
	// 변수 선언
	int var1, var2, var3, var4, var5;

	int result;

	cout << "1번째 정수 입력 : ";
	cin >> var1;

	cout << "2번째 정수 입력 : ";
	cin >> var2;

	cout << "3번째 정수 입력 : ";
	cin >> var3;

	cout << "4번째 정수 입력 : ";
	cin >> var4;

	cout << "5번째 정수 입력 : ";
	cin >> var5;

	result = var1 + var2 + var3 + var4 + var5;

	cout << "합계 : " << result;
}