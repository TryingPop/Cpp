#include<vector>

/*
날짜 : 2024. 3. 21
이름 : 배성훈
내용 : 머쓱이보다 키 큰 사람
	정수 배열 array와 키 height가 매개변수로 주어질 때,
	height보다 큰 array의 원소의 개수를 
	return 하는 solution 함수 구현
*/

using namespace std;

int solution(vector<int> _array, int _height)
{

	int answer = 0;

	for (const int i : _array)
	{

		if (i > _height) answer++;
	}

	return answer;
}