#include <vector>

/*
날짜 : 2024. 2. 25
이름 : 배성훈
내용 : 배열 만들기 6
	0과 1로만 이루어진 정수 배열 arr이 주어진다
	arr을 이용해 새로운 stk배열을 만든다

	i의 초기값을 0으로 하고, i가 arr의 길이보다 작으면

	만약 stk가 빈 배열이면, arr[i]를 stk에 추가하고 i+ 1,

	stk에 원소가 있고 stk의 마지막 원소가 arr[i]와 같으면
	stk의 마지막 원소를 stk에서 제거하고 i + 1,

	stk에 원소가 있는데 stk의 마지막 원소가 arr[i]와 다르면
	stk의 맨 마지막에 arr[i]에 1을 더하고 i + 1

	위 작업을 마친 후 만들어진 
	stk를 return하는 solution 함수 구현

	만약 작업 후 stk가 빈 배열이라면 { -1 }을 반환
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> stk;

	for (int i = 0; i < _arr.size(); i++)
	{

		if (stk.empty()) stk.push_back(_arr[i]);
		else if (stk.back() == _arr[i]) stk.pop_back();
		else stk.push_back(_arr[i]);
	}

	if (stk.empty()) stk.push_back(-1);

	return stk;
}