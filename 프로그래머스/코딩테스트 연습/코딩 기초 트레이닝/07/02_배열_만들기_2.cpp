#include <vector>
#include <string>
#include <cmath>

/*
날짜 : 2024. 2. 13
이름 : 배성훈
내용 : 배열 만들기 2
	정수l과 r이 주어졌을 때, l이상 r이하의 정수 중에서 숫자 "0"과 "5"로만
	이루어진 모든 정수를 오름차순으로 저장한 배열을 return하는 soltuion 함수 만들기
	만약 그러한 정수가 없다면 -1이 담긴 배열을 return

	수의 범위가 100만이기에 그냥 무식하게 for문을 돌렸다
	만약 수의 범위가 1000만 이상이면 직접 찾는 방식을 이용했을 것이다
*/

using namespace std;

vector<int> solution(int _l, int _r)
{

	vector<int> answer;
#if first
	for (int i = _l; i <= _r; i++) 
	{

		string str = to_string(i);
		bool chk = true;
		for (int j = 0; j < str.length(); j++)
		{

			if (str[j] == '5' || str[j] == '0') continue;
			
			chk = false;
			break;
		}

		if (chk) answer.push_back(i);
	}
	if (answer.empty()) answer.push_back(-1);
#else

	{

		vector<string> calc;
		vector<string> temp;
		// 2 ^ 7의 자리만큼 공간 확보! ( 2^0 + 2^1 + ... + 2^6)
		// cmath 불러와야 pow를 불러올 수 있다
		calc.reserve(pow(2, 7));
		temp.reserve(pow(2, 7));
		calc.push_back("");

		for (int i = 0; i < 6; i++) 
		{

			for (int j = 0; j < calc.size(); j++) 
			{

				temp.push_back(calc[i] + "0");
				temp.push_back(calc[i] + "5");
			}

			calc = temp;
			temp.clear();
		}

		for (int i = 0; i < calc.size(); i++) 
		{

			int chk = stoi(calc[i]);
			if (chk >= _l && chk <= _r) answer.push_back(chk);
		}
	}


#endif


	return answer;
}