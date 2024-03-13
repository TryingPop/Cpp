#include <vector>

/*
날짜 : 2024. 3. 13
이름 : 배성훈
내용 : 주사위의 개수
	가로, 세로, 높이가 저장되어져 있는
	정수형 배열 box와

	정육면체 주사위 모서리 길이의 정수 n이
	매개변수로 주어질 때,

	상자에 들어갈 수 있는 주사위의 최대 개수를 
	return 하는 solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _box, int _n)
{

	int answer = _box[0] / _n;
	answer *= _box[1] / _n;
	answer *= _box[2] / _n;

	return answer;
}