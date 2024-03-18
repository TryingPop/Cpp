#include <vector>

/*
날짜 : 2024. 3. 18
이름 : 배성훈
내용 : 가장 큰 수 찾기
	정수 배열 array가 매개변수로 주어질 때,
	가장 큰 수와 그 수의 인덱스를 담은 배열을
	return 하도록 solution 함수를 구현

	array에 중복된 값은 없다
*/

using namespace std;

vector<int> solution(vector<int> _array)
{

	vector<int> answer(2, 0);
	answer[0] = _array[0];

	for (int i = 1; i < _array.size(); i++)
	{

		if (_array[i] <= answer[0]) continue;

		answer[0] = _array[i];
		answer[1] = i;
	}
	return answer;
}