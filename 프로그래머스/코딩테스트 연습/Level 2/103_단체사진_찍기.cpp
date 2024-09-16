/*
날짜 : 2024. 9. 16
이름 : 배성훈
내용 : 단체사진 찍기
	가을을 맞아 카카오프렌즈는 단체로 소풍을 떠났다
	즐거운 시간을 보내고 마지막에 단체 사진을 찍기 위해 카메라 앞에 일렬로 나란히 섰다
	그런데 각자가 원하는 배치가 모두 달라 어떤 순서로 설지 정하는데 시간이 오래 거렬ㅆ다
	사진을 찍고 나서 돌아오는 길에, 무지는 모두가 원하는 조건을 만족하면서도
	다르게 서는 방법이 있지 않을까 생각해보게 되었다

	각 프렌즈가 원하는 조건을 입력으로 받았을 때
	모든 조건을 만족할 수 있도록 서는 경우의 수를
	계산하는 프로그램을 구현

	입력은 조건의 개수를 나타내는 정수 n과 
	n개의 원소로 구성된 문자열 배열 data가 주어진다

	data의 원소는 각 프랜즈가 원하는 조건이 N~F=0과 같은 
	형태의 문자열로 구성되어 있다

	n은 100 이하의 자연수
	data의 원소는 다섯 글자로 구성된 문자열이다
	첫 번째 글자와 세 번째 글자는 다음 8개 중 하나이다
	{ A, C, F, J, M, N, R, T }
	각각 캐릭터를 의미
	첫 번째 글자는 조건을 제시한 프렌즈, 세번째 글자는 상대방이고 
	첫 번째 글자와 세 번째 글자는 항상 서로 다르다

	두 번째 글자는 항상 ~ 이다

	네 번째 글자는 { =, <, > } 중 하나이고 각각 같음, 미만, 초과를 의미한다
	다섯 번째 글자는 0 이상 6 이하인 정수의 문자형이며
	조건에 제시되는 간격을 의미한다
	이 때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수이다

	모든 조건을 만족하는 경우의 수를 리턴한다

	parameter
	2, { "M~C<2", "C~M>1" }


	return
	0

	
	sol
	M은 C와 2칸 미만 간격을 원한다
	반면 C는 M과 1칸 초과 간격을 원하는데 이는 서로 모순이므로
	0개이다
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nTi[128], order[8];
bool use[8];

vector<vector<int>> dis;

inline void SetDis() 
{

	/*
	
	order에 맞춰 dis 설정
	*/
	for (int i = 0; i < 8; i++)
	{

		int idx1 = order[i];
		for (int j = i + 1; j < 8; j++)
		{

			int idx2 = order[j];
			dis[idx1][idx2] = j - i - 1;
			dis[idx2][idx1] = j - i - 1;
		}
	}
}

inline bool ReadString(string& _str)
{

	/*
	
	문자열 순서가 지켜지는지 확인
	*/
	int f = nTi[_str[0]];
	int b = nTi[_str[2]];

	int op = _str[3];
	int val = _str[4] - '0';

	if (op == '<') return dis[f][b] < val;
	else if (op == '>') return dis[f][b] > val;
	else return dis[f][b] == val;
}

inline int DFS(vector<string>& _data, int _depth = 0)
{

	/*
	
	순서 정하고 가능한 경우를 반환
	*/
	if (_depth == 8)
	{

		SetDis();
		for (string& d : _data)
		{

			if (ReadString(d)) continue;
			return 0;
		}

		return 1;
	}

	int ret = 0;
	for (int i = 0; i < 8; i++)
	{


		if (use[i]) continue;
		use[i] = true;

		order[_depth] = i;
		ret += DFS(_data, _depth + 1);
		use[i] = false;
	}

	return ret;
}

inline void Init() 
{

	/*
	
	초기화 함수
	*/
	dis.resize(8, vector<int>(8));

	for (int i = 0; i < 8; i++)
	{

		use[i] = false;
		order[i] = 0;
	}

	nTi['A'] = 0, nTi['C'] = 1, nTi['F'] = 2, nTi['J'] = 3;
	nTi['M'] = 4, nTi['N'] = 5, nTi['R'] = 6, nTi['T'] = 7;
}

int solution(int _n, vector<string> _data)
{

	/*
	
	브루트 포스
	경우의 수를 계산해보니 8! < 5만,
	data의 길이 100 이하
	그래서 전체 500만 정도의 연산이므로 브루트포스로 잡았다
	*/
	Init();
	int answer = DFS(_data);
	return answer;
}