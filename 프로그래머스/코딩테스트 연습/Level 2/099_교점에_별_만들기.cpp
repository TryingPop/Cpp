/*
��¥ : 2024. 9. 12
�̸� : �輺��
���� : ������ �� �����
	Ax + By + C = 0 ���� ǥ���� �� �ִ�
	n���� ������ �־��� ��,

	�� ������ ���� �� ���� ��ǥ�� ���� �׸��� �Ѵ�

	���� A, B, C�� ���� ������ ��� �迭 line�� �Ű������� �־��� ��,
	�̶� ��� ���� �����ϴ� �ּ� �簢���� return �ϴ� solution �Լ� ����

	line�� ���� ���̴� 1000���� 2�̻��� �ڿ���
	line�� ���� ���̴� 3���� �����Ǿ� �ְ� { A, B, C } ���´�
	A, B, C�� -10�� �̻��̰� 10�� ������ �����̴�
	A = 0�̸鼭 B = 0�� ���� �־����� �ʴ´�

	������ 1000 x 1000 ũ�� ������ ǥ���ȴ�
	���� �� �� �̻� �׷����� �Է¸� �־�����

	parameter
	{ { 2, -1, 4 }, { -2, -1, 4 }, { 0, -1, 1 }, { 5, -8, -12 }, { 5, 8, 12 } }

	
	return
	{ "....*....", 
	  ".........", 
	  ".........", 
	  "*.......*", 
	  ".........", 
	  ".........", 
	  ".........", 
	  ".........", 
	  "*.......*" }


	sol
	������ ���� ��ǥ�� �������� ��� ���ϸ�
	(0, 4), (-4, 1), (4, 1), (-4, -4), (4, 4)
	�̴� �̸� ǥ���ϸ� ����ó�� �ȴ�
*/

#include <vector>
#include <string>
#include <utility>

#define ll long long

#define pll pair<ll, ll>
#define mp make_pair

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))

using namespace std;

inline bool NotMeetLine(vector<int>& _f, vector<int>& _g)
{

	/*
	
	�������� �������� Ȯ��
	*/
	return _f[0] * _g[1] == _f[1] * _g[0];
}

inline bool NotMeetPos(vector<int>& _f, ll _x, ll _y)
{

	/*
	
	���� �������� �ִ��� Ȯ��
	*/
	return _f[0] * _x + _f[1] * _y + _f[2] != 0;
}

inline void GetMeetPos(vector<vector<int>>& _line, vector<pll>& _meet)
{

	/*
	
	�����鰣 ������ ������ǥ ���� meet�� ��´�
	*/
	for (int i = 1; i < _line.size(); i++)
	{

		vector<int>& f = _line[i];

		for (int j = 0; j < i; j++)
		{

			if (NotMeetLine(_line[i], _line[j])) continue;
			vector<int>& g = _line[j];

			ll bot = (1LL * f[1] * g[0] - 1LL * g[1] * f[0]);

			ll gx = (1LL * f[2] * g[1] - 1LL * f[1] * g[2]) / bot;
			ll gy = (1LL * f[0] * g[2] - 1LL * f[2] * g[0]) / bot;

			if (NotMeetPos(f, gx, gy)
				|| NotMeetPos(g, gx, gy)) continue;

			_meet.push_back(mp(gx, gy));
		}
	}
}

inline void DrawMap(vector<string>& _map, vector<pll>& _meet)
{

	/*
	
	�ּһ������� ���� ���ϱ�
	*/
	ll minX = 1e15, minY = 1e15, maxX = -1e15, maxY = -1e15;

	for (pll& pos : _meet)
	{

		minX = Min(minX, pos.first);
		maxX = Max(maxX, pos.first);

		minY = Min(minY, pos.second);
		maxY = Max(maxY, pos.second);
	}

	string temp(maxX - minX + 1, '.');
	_map.resize(maxY - minY + 1, temp);

	for (pll& pos : _meet)
	{

		ll x = pos.first - minX;
		ll y = maxY - pos.second;

		_map[y][x] = '*';
	}
}

vector<string> solution(vector<vector<int>> _line)
{

	/*
	
	���� ����
	*/
	vector<string> answer;
	vector<pll> meet;

	GetMeetPos(_line, meet);
	DrawMap(answer, meet);
	return answer;
}