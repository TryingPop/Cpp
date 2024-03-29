#include <string>

/*
날짜 : 2024. 3. 29
이름 : 배성훈
내용 : 문자열 밀기
	문자열 A와 B가 매개변수로 주어질 때,
	A를 밀어서 B가 될 수 있다면
	밀어야 하는 최소 횟수를 return하고
	밀어서 B가 될 수 없다면 -1을
	return 하는 solution 함수 구현


	hello의 경우 1회 민다는 것은
	방향을 오른쪽으로 1회 회전 시키는 것과 같다
	그래서 hello -> ohell 이 된다

	만약 int가 여러 개 존재하면,
	최소 횟수를 출력한다

	A와 B의 길이는 같다
*/

using namespace std;

int solution(string _A, string _B)
{

	int answer = -1;

	for (int i = 0; i < _A.size(); i++)
	{

		bool find = true;
		for (int j = 0; j < _A.size(); i++)
		{

			int idx = (i + j) % _A.size();
			if (_A[i] == _B[idx]) continue;

			find = false;
			break;
		}

		if (find)
		{

			answer = i;
			break;
		}
	}

#if other

	_B.reserve(2 * _A.size());
	_B += _B;
	answer = _B.find(_A);
#endif
	return answer;
}