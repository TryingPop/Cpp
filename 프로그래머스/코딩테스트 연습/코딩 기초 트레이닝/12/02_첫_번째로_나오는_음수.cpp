#include <vector>

/*
날짜 : 2024. 2. 18
이름 : 배성훈
내용 : 첫 번째로 나오는 음수
	정수 리스트 num_list가 주어질 때,
	첫 번째로 나오는 음수의 인덱스를 return 하도록 
	solution 함수를 완성
	음수가 없다면 -1을 return
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer = -1;

	for (int i = 0; i < _num_list.size(); i++)
	{

		if (_num_list[i] < 0) 
		{ 

			answer = i; 
			break;
		}
	}

	return answer;
}