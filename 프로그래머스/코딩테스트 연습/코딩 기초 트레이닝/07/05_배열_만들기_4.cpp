#include <vector>

/*
날짜 : 2024. 2. 13
이름 : 배성훈
내용 : 배열 만들기 4
	정수 배열 arr이 주어진다
	arr을 이용해 새로운 배열 stk를 만든다

	변수 i를 만들어 초기값을 0으로 설정한 후 i가 arr의 길이보다 작으면 다음 작업을 반복
	만약 stk가 빈 배열이라면 arr[i]를 stk에 추가하고 i에 1을 더한다
	stk에 원소가 있고, stk의 마지막 원소가 arr[i]보다 작으면 arr[i]를 stk의 뒤에 추가하고 i에 1을 더한다
	stk에 원소가 있는데 stk의 마지막 원소가 arr[i]보다 크거나 같으면 stk의 마지막 원소를 stk에서 제거한다

	위 작업을 마치고 만들어지는 stk를 return하는 solution 함수 만들기
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> stk;

	for (int i = 0; i < _arr.size(); i++) 
	{

		if (stk.empty()) stk.push_back(_arr[i]);
		else if (stk.back() < _arr[i]) stk.push_back(_arr[i]);
		else 
		{

			stk.pop_back();
			i--;
		}
	}
	return stk;
}