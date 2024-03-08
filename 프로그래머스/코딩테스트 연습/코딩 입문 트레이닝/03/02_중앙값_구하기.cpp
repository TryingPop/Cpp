#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 8
이름 : 배성훈
내용 : 중앙값 구하기
	정수 배열 array가 매개변수로 주어질 때,
	중앙값을 return 하는 solution 함수 구현

	중앙값이란 오름차순으로 정렬 했을 때,
	가장 중앙에 있는 원소를 의미
*/

using namespace std;

int solution(vector<int> _array)
{

	int answer;
	sort(_array.begin(), _array.end());
	// 중앙에 있는 인덱스를 가리킨다
	int mid = _array.size() / 2;
	answer = _array[mid];
	return answer;
}