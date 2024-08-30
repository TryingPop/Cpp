/*
��¥ : 2024. 8. 30
�̸� : �輺��
���� : ���� �����ϱ�
	������ ���� ��� ������ ���� ������� 
	������ �Ϸ��� ��ȹ�� ������

	������ �����ϱ�� �� �ð��� �Ǹ� �����Ѵ�

	���ο� ������ ������ �ð��� �Ǿ��� ��,
	������ ���� ���̴� ������ �ִٸ�
	���� ���̴� ������ ���߰� ���ο� ������ �����Ѵ�

	���� ���̴� ������ ������ ��,
	��� ���� ������ �ִٸ�, ����� ������ �̾ �����Ѵ�
	
	���� ������ ���� �ð��� ���� �����ؾ� �Ǵ� ������
	����� ������ ��� �ִٸ� ���� �����ؾ� �ϴ� �������� �����Ѵ�

	����� ������ ���� ���� ���, ���� �ֱٿ� ���� �������� �����Ѵ�

	���� ��ȹ�� ���� ������ ���ڿ� �迭 plans�� �Ű������� �־��� ��,
	������ ���� ������� �̸��� �迭�� ��� return �ϴ� solution �Լ� ����

	plans�� ���̴� 1000 ����

	plans�� ���Ҵ� { name, start, playtime }�� ������ �̷���� �ִ�
	name : ������ �̸�, start : ������ ���� �ð�, playtime : ������ ��ġ�µ� �ɸ��� �ð�
	�� �ǹ��ϰ�
	������ �̸��� �ߺ��Ȱ� ���� ���ĺ� �ҹ��ڷθ� �̷���� �ִ�

	������ ���� �ð��� hh:mm �����̰� 00:00 ~ 23:59 ������ �ð��� �ִ�
	00:00, ..., 23:59 ������ �����ϸ� �ȴ�

	������ ��ġ�� �ð��� ���������� ���ڿ��̸� ���ڷ� �ٲ��� �� 100 ������ �ڿ����̴�

	�迭�� �ð������� ���ĵǾ� ���� �ʴ�

	�������̴� ������ ������ �ð��� ���ο� ������ �����ؾ��ϴ� �ð��� ���� ���
	���� ���̴� ������ ���������� �Ǵ��Ѵ�

	parameter
	{ { "korean", "11:40", "30" }, { "english", "12:10", "20" }, 
	  { "math", "12:30", "40" } }


	return
	{ "korean", "english", "math" }


	sol
	���� �ð��� ���� ���� korean���� �����Ѵ�
	12:10�п� korean�� �Ϸ�ǰ�

	english�� �����Ѵ�
	12:30�п� english�� �Ϸ�ǰ�

	math�� �����Ѵ�

	�׷��� korean, english, math ������ ������
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define NUM(X) (X - '0')
#define INF 123'456

using namespace std;

struct HW
{

	/*
	
	������ ���� �ڷᱸ��
	�������� ���ڿ����̱⿡ ���ڷ� ��ȯ�� �� �ִ°� ���ڷ� ��ȯ�Ѵ�
	*/
	string name;
	int start;		// 00:00���� �� �� �귶���� ���ڷ� ��ȯ
	int playtime;

	HW(string& _name, int _start, int _playtime)
		: name(_name), start(_start), playtime(_playtime) { }
};

inline bool MyComp(const vector<string>& _f, const vector<string>& _b)
{

	/*
	
	���ڿ� ���̰� ������ ����ó�� ���Ѵ�
	*/
	return _f[1] < _b[1];
}

inline int GetStart(const string& _start)
{

	/*
	
	�ð� ���
	*/
	int h = NUM(_start[0]) * 10 + NUM(_start[1]);
	int m = NUM(_start[3]) * 10 + NUM(_start[4]);

	return h * 60 + m;
}

inline int GetPlayTime(const string& _playtime)
{

	/*
	
	string�� ���ڷ� �ٲ۴�
	*/
	int ret = 0;
	for (const char c : _playtime)
	{

		ret = ret * 10 + c - '0';
	}

	return ret;
}

inline void GetHW(vector<vector<string>>& _plans, vector<HW>& _hw)
{

	/*
	
	HW �ڷᱸ���� ��ȯ�Ѵ�
	*/
	_hw.reserve(_plans.size());
	for (vector<string>& p : _plans)
	{

		_hw.push_back(HW(p[0], GetStart(p[1]), GetPlayTime(p[2])));
	}
}

inline void GetRet(vector<HW>& _hw, vector<string>& _ret)
{

	/*
	
	���� �ùķ��̼�
	*/

	// �ٷ� �� ���� �����ϴ� ���� �ڷᱸ��
	stack<HW> stk;

	int s = 0;
	for (int i = 0; i < _hw.size(); i++)
	{

		// ���� ���� ���� �ð� ���� ��� INF
		int e = i + 1 == _hw.size() ? INF : _hw[i + 1].start;

		s = _hw[i].start;

		// ���� �ð����� ���� �ð�
		int playtime = e - s;

		if (playtime < _hw[i].playtime)
		{

			// �ð��� ������ ���� ������ �� ������ ���
			_hw[i].playtime -= playtime;
			stk.push(_hw[i]);
			continue;
		}

		// ���� ������ ���� ��ŭ �ð��� �ִ� ���
		playtime -= _hw[i].playtime;
		_ret.push_back(_hw[i].name);

		// ���� ���� �ִ��� Ȯ���ϰ� ���� ���� �ִ��� ����
		while (playtime > 0 && stk.size())
		{

			HW& hw = stk.top();
			if (hw.playtime <= playtime)
			{

				playtime -= hw.playtime;
				stk.pop();
				_ret.push_back(hw.name);
				continue;
			}

			hw.playtime -= playtime;
			playtime = 0;
		}
	}

	// ���� ������ Ǭ��
	// ���⼭�� ����� ũ�� e ���� ��� ������ �Ⱦ��δ�
	while (stk.size())
	{

		HW& hw = stk.top();
		_ret.push_back(hw.name);
		stk.pop();
	}
}

vector<string> solution(vector<vector<string>> _plans)
{

	/*
	
	����, ���� ����
	*/
	vector<string> answer;
	answer.reserve(_plans.size());

	// ���� �ð� ������ ����
	sort(_plans.begin(), _plans.end(), MyComp);

	// �Էµ� plans�� ���ڿ��� �̷��� �����Ƿ�
	// ���ڷ� ��ȯ ������ �͵��� ���ڷ� ��ȯ�� �ڷᱸ���� �ٲ۴�
	vector<HW> hw;
	GetHW(_plans, hw);

	// ��� ����
	GetRet(hw, answer);

	return answer;
}