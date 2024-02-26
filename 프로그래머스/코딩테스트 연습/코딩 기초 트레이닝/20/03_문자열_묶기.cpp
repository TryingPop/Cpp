#include <vector>
#include <string>

/*
날짜 : 2024. 2. 26
이름 : 배성훈
내용 : 문자열 묶기
	문자열 배열 strArr이 주어진다
	strArr의 원소들을 길이가 같은 문자열들끼리
	그룹으로 묶었을 때 가장 개수가 많은 그룹의 크기를
	return 하는 solution 함수를 구현
*/

using namespace std;

int solution(vector<string> _strArr)
{

	int answer = 0;

	int temp[31]{ 0, };

	for (const string str : _strArr)
	{

		int size = str.length();
		temp[size]++;
	}

	for (int i = 1; i <= 30; i++) 
	{

		if (answer < temp[i]) answer = temp[i];
	}

	return answer;
}