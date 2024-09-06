/*
날짜 : 2024. 9. 6
이름 : 배성훈
내용 : 숫자 블록
	그렙시에는 숫자 0이 적힌 블록들이 설치된 도로에
	다른 숫자가 적힌 블록들을 설치하기로 하였다

	숫자 블록을 설치하는 규칙은 다음과 같다
	블록에 적힌 번호가 n일 때, 가장 첫 블록은 n * 2 위치에 설치한다
	그 다음은 n * 3, ... , n *k ,... 위치에 설치한다
	기존에 설치된 블록이 있으면 빼고 새로운 블록을 집어 넣는다

	블록은 1이 적힌 블록부터 숫자를 1씩 증가시키며 순서대로 설치한다
	
	그렙시는 길이가 1억인 도로에 1부터 1000만까지의 숫자가 적힌 블록들을
	이용해 위의 규칙대로 모두 설치했다

	그렙시의 사장님은 특정 구간에 어떤 블록이 깔려 있는지를 확인하고 싶다

	구간을 나타내는 두 정수 begin, end가 매개변수로 주어질 때,
	그 구간에 깔려 있는 블록의 숫자 배열을 return 하는 solution 함수 구현

	begin, end는 10억 이하의 자연수 이고, 
	begin <= end이고, end - begin <= 5000이다


	parameter
	1, 10


	return
	{ 0, 1, 1, 2, 1, 3, 1, 4, 3, 5 }


	sol
	1번을 깐다
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	2번을 깐다
	{ 0, 1, 1, 2, 1, 2, 1, 2, 1, 2 }
	3번을 깐다
	{ 0, 1, 1, 2, 1, 3, 1, 2, 3, 2 }
	4번을 깐다
	{ 0, 1, 1, 2, 1, 3, 1, 4, 3, 2 }
	5번을 깐다
	{ 0, 1, 1, 2, 1, 3, 1, 4, 3, 5 }
	6번부터는 변하는 숫자가 10을 넘어가므로 확인할 필요가 없다

	그래서 결과로
	{ 0, 1, 1, 2, 1, 3, 1, 4, 3, 5 }
	이된다
*/

#include <vector>

#define ll long long

using namespace std;

vector<int> solution(ll _begin, ll _end)
{

	/*
	
	수학 - 에라토스테네스 체
	*/

	vector<int> answer;
	answer.reserve(_end - _begin + 1);

	for (int i = _begin; i <= _end; i++)
	{

		int add = i == 1 ? 0 : 1;
		for (int j = 2; j * j <= i; j++)
		{

			if (i % j) continue;
			add = i / j;

			if (add > 10'000'000)
			{

				add = j;
				continue;
			}

			break;
		}

		answer.push_back(add);
	}

	return answer;
}