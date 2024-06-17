/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 카펫
	중앙에 노란색으로 칠해져 있고,
	테두리 1줄은 갈색으로 칠해져 있는 격자모양의 카펫이 존재한다

	노란색과 갈색으로 색칠된 격자의 개수는 기억하지만,
	전체 카펫의 크기는 기억하지 못한다

	갈색 격자의 수를 brown, 노란색 격자의 수를 yellow가
	매개변수로 주어질 때,

	카펫의 가로, 세로 크기를 순서대로 배열에 담아
	return 하도록 solution 함수를 구현

	갈색격자의 수는 8 이상 5'000 이하의 자연수
	노란색 격자의 수는 1 이상 2'000'000 이하의 자연수
	카펫의 가로 길이는 세로 길이 이상이다

	parameter
	24, 24


	return
	8, 6
*/

#include <vector>

using namespace std;

vector<int> solution(int _brown, int _yellow)
{

	vector<int> answer;

	int sum = _brown + _yellow;
	for (int h = 1; h * h <= sum; h++)
	{

		if (sum % h) continue;

		int w = sum / h;

		int outline = 2 * (w + h) - 4;
		if (outline != _brown) continue;

		answer.push_back(w);
		answer.push_back(h);

		break;
;	}

	return answer;
}