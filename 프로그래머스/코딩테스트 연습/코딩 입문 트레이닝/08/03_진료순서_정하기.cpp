#include <vector>
#include <algorithm>

#include <map>

/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 진료 순서 정하기
	응급도를 나타내는 정수 배열 emergency가 매개변수로 주어질 때,
	응급도가 높은 순서대로 진료 순서를 정한 배열을
	return 하는 solution 함수 구현

	_emergency의 응급도는 100이하인 음이아닌 정수이고 중복된 값은 없다
*/

using namespace std;

vector<int> solution(vector<int> _emergency)
{

	vector<int> answer(_emergency.size());

	vector<int> varToIdx(101, -1);

	for (int i = 0; i < _emergency.size(); i++) 
	{

		varToIdx[_emergency[i]] = i;
	}

	sort(_emergency.begin(), _emergency.end(), greater<int>());

	for (int i = 0; i < _emergency.size(); i++)
	{

		answer[varToIdx[_emergency[i]]] = i + 1;
	}

	/*
	map<int, int> temp = map<int, int>();
	
	for (const int i : _emergency)
	{

		temp[i];
	}

	int order = _emergency.size();

	// 맵은 키에따라 알아서 오름차순 정렬 해준다
	// 값을 변환하기에 주소로 받아온다
	for (pair<const int, int>& ptr : temp) 
	{

		ptr.second = order--;
	}

	for (const int i : _emergency) 
	{

		answer.push_back(temp[i]);
	}
	*/
	
	return answer;
}