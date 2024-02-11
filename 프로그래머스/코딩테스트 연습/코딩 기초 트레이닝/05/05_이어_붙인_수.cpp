#include <vector>

/*
날짜 : 2024. 2. 11
이름 : 배성훈
내용 : 이어 붙인 수
	정수가 담긴 리스트 _num_list가 주어진다
	홀수만 순서대로 이어붙인 수와 짝수만 이어붙인 수의 합울 return하는 함수 만들기

	리스트 안의 수는 1 ~ 9사이의 정수!
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;

	int odd = 0;
	int even = 0;
	
	for (const int c : _num_list)
	{

		if (c & 1)
		{ 
			
			odd *= 10;
			odd += c; 
		}
		else 
		{ 
		
			even *= 10;
			even += c; 
		}
	}

	answer = odd + even;
	return answer;
}