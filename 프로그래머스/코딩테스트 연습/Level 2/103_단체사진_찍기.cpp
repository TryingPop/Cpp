/*
��¥ : 2024. 9. 16
�̸� : �輺��
���� : ��ü���� ���
	������ �¾� īī��������� ��ü�� ��ǳ�� ������
	��ſ� �ð��� ������ �������� ��ü ������ ��� ���� ī�޶� �տ� �Ϸķ� ������ ����
	�׷��� ���ڰ� ���ϴ� ��ġ�� ��� �޶� � ������ ���� ���ϴµ� �ð��� ���� �ŷĤ���
	������ ��� ���� ���ƿ��� �濡, ������ ��ΰ� ���ϴ� ������ �����ϸ鼭��
	�ٸ��� ���� ����� ���� ������ �����غ��� �Ǿ���

	�� ����� ���ϴ� ������ �Է����� �޾��� ��
	��� ������ ������ �� �ֵ��� ���� ����� ����
	����ϴ� ���α׷��� ����

	�Է��� ������ ������ ��Ÿ���� ���� n�� 
	n���� ���ҷ� ������ ���ڿ� �迭 data�� �־�����

	data�� ���Ҵ� �� ����� ���ϴ� ������ N~F=0�� ���� 
	������ ���ڿ��� �����Ǿ� �ִ�

	n�� 100 ������ �ڿ���
	data�� ���Ҵ� �ټ� ���ڷ� ������ ���ڿ��̴�
	ù ��° ���ڿ� �� ��° ���ڴ� ���� 8�� �� �ϳ��̴�
	{ A, C, F, J, M, N, R, T }
	���� ĳ���͸� �ǹ�
	ù ��° ���ڴ� ������ ������ ������, ����° ���ڴ� �����̰� 
	ù ��° ���ڿ� �� ��° ���ڴ� �׻� ���� �ٸ���

	�� ��° ���ڴ� �׻� ~ �̴�

	�� ��° ���ڴ� { =, <, > } �� �ϳ��̰� ���� ����, �̸�, �ʰ��� �ǹ��Ѵ�
	�ټ� ��° ���ڴ� 0 �̻� 6 ������ ������ �������̸�
	���ǿ� ���õǴ� ������ �ǹ��Ѵ�
	�� �� ������ �� ������ ���̿� �ִ� �ٸ� �������� ���̴�

	��� ������ �����ϴ� ����� ���� �����Ѵ�

	parameter
	2, { "M~C<2", "C~M>1" }


	return
	0

	
	sol
	M�� C�� 2ĭ �̸� ������ ���Ѵ�
	�ݸ� C�� M�� 1ĭ �ʰ� ������ ���ϴµ� �̴� ���� ����̹Ƿ�
	0���̴�
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
	
	order�� ���� dis ����
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
	
	���ڿ� ������ ���������� Ȯ��
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
	
	���� ���ϰ� ������ ��츦 ��ȯ
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
	
	�ʱ�ȭ �Լ�
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
	
	���Ʈ ����
	����� ���� ����غ��� 8! < 5��,
	data�� ���� 100 ����
	�׷��� ��ü 500�� ������ �����̹Ƿ� ���Ʈ������ ��Ҵ�
	*/
	Init();
	int answer = DFS(_data);
	return answer;
}