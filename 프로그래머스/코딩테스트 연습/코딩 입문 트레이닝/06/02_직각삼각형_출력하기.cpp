#include <iostream>
#include <string>

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 직각삼각형 출력하기
	'*'의 높이와 너비를 1이라고 할 때,
	'*'를 이용해 직각 이등변 삼각형을 그리려고 한다

	정수 n이 주어지면 높이와 너비가 n인 
	직각 이등변 삼각형을 출력하는 코드를 작성
*/

using namespace std;

int main(void)
{

	int n;
	string temp;

	cin >> n;
	temp.reserve(n);

	for (int i = 0; i < n; i++)
	{

		temp.push_back('*');
		cout << temp << '\n';
	}
	
	return 0;
}