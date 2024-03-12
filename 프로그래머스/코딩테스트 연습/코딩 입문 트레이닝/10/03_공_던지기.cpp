#include<vector>

/*
날짜 : 2024. 3. 12
이름 : 배성훈
내용 : 공 던지기
	원형으로 서서 공 던지기 놀이를 하는 중이다
	공은 맨 앞에 있는 사람 1번부터 던지며
	오른쪽으로 한 명을 건너뛰고 그 다음사람에게 전달한다

	정수 배열 numbers와 정수 k가 주어질 때,
	k번째로 공을 던지는 사람 번호를
	return 하는 solution 함수 구현
*/

using namespace std;

int solution(vector<int> _numbers, int _k)
{

	int answer;
	// 2칸씩 건너뛴다, 0 -> 2 - > 4 -> ...
	// 그래서 _k * 2를 하고, 처음이 0번 인덱스이므로 -2를 해준다
	// 원형이므로 나머지 연산도 해준다
	int idx = (_k * 2 - 2) % _numbers.size();
	answer = _numbers[idx];
	return answer;
}