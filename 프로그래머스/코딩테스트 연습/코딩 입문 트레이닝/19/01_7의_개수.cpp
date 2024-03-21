#include <string>
#include <vector>

/*
날짜 : 2024. 3. 21
이름 : 배성훈
내용 : 7의 개수
	정수 배열 array가 매개변수로 주어질 때,
	7이 총 몇개 있는지 return 하도록
	solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _array) 
{

	int answer;

	for (const int i : _array)
	{

		string numStr = to_string(i);

		for (const char c : numStr)
		{

			if (c == '7') answer++;
		}
	}

	return answer;
}