/*
��¥ : 2024. 8. 10
�̸� : �輺��
���� : �޴� ������
	��������� ��ϴ� ��ī�Ǵ� �ڷγ�19�� ����
	�Ұ�⸦ �غ��ϰ��� �޴��� ���� �����Ϸ��� ����ϰ� �ִ�

	�������� ��ǰ���θ� �����ϴ� �޴��� �����ؼ�
	�ڽ��丮 ���·� �籸���ؼ� ���ο� �޴��� �����ϱ�� �����ߴ�

	� ��ǰ�޴����� �����ؼ� �ڽ��丮 �޴��� �����ϸ� ������
	����ϴ� ��ī�Ǵ� ������ �� �մԵ��� �ֹ��� �� ���� ���� �Բ� �ֹ���
	��ǰ�޴����� �ڽ��丮 �޴��� �����ϱ�� �ߴ�

	�� �ڽ��丮 �޴��� �ּ� 2���� �̻��� ��ǰ�޴��� �����Ϸ��� �Ѵ�
	���� �ּ� 2�� �̻��� �մ����κ��� �ֹ��� ��ǰ�޴� ���տ� ���ؼ���
	�ڽ��丮 �޴� �ĺ��� �����ϱ�� �ߴ�

	�� �մԵ��� �ֹ��� ��ǰ�޴����� ���ڿ� �������� ��� �迭 orders,
	��ī�ǰ� �߰��ϰ� �;��ϴ� �ڽ��丮�� �����ϴ� ��ǰ�޴����� ������ ���
	�迭 course�� �Ű������� �־��� ��,

	��ī�ǰ� ���� �߰��ϰ� �� �ڽ��丮�� �޴� ������ ���ڿ� ���·� �迭�� ���
	return �ϴ� solution �Լ� ����

	orders �迭�� ũ��� 2�̻� 20����

	orders �迭�� �� ���Ҵ� ũ�Ⱑ 2 �̻� 10 ������ ���ڿ�
	�� ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� �ִ�
	�� ���ڿ����� ���� ���ڿ��� �ߺ��ؼ� �� ���� �ʴ�

	������ �� �ڽ��丮 �޴��� ������ ���ڿ� �������� �迭�� ��� ���� ������
	�������� �����ؼ� return ���ּ���
	�迭�� �� ���ҿ� ����� ���ڿ� ���� ���ĺ� ������������ ���ĵǾ�� �Ѵ�
	���� ���� ���� �Բ� �ֹ��� �޴� ������ ���� �����, ��� �迭�� ��� return
	orders�� course �Ű������� return �ϴ� �迭�� ���̰� 1 �̻��� �ǵ��� �־�����

	(��ǰ �޴� �������� �ִ� ������ �ش��ϴ� �ڽ��丮�� �迭�� ��ƾ� �Ѵ�)

	parameter
	{ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 }


	return
	{ "ACD", "AD", "ADE", "CD", "XYZ" }


	sol
	2��, 3��, 5���� ������ �ڽ��丮���� ã�ƾ��Ѵ�
	���⼭ �ּ� 2�� �̻��� ���� 2��¥�� �ڽ��丮���� ����
	"AB", "CD", "AC", "AD", "XY", "YZ", "XZ", "DE", "AE"�� �����ϴµ�
	���⼭ "AD", "CD"�� 3���̰� �������� 2���� �Ծ� �ĺ����� Ż���ȴ�

	3��¥�� �丮�� ã�ƺ���
	"ACD", "ADE", "XYZ"�� �ְ�
	�̵� ��� 2���̹Ƿ� �ڽ��丮 �ĺ��� �ȴ�

	5��¥���� "ABCDE"�� �����ϰ� 1�� �Ծ����Ƿ� �߰����� �ʴ´�

	�׷��� ���������
	"AD", "CD", "ACD", "ADE", "XYZ"�ε� �̵��� �����ϸ�

	"ACD", "AD", "ADE", "CD", "XYZ"
	�� �ȴ�
*/

#include <vector>
#include <algorithm>
#include <string>

#if !first
#include <unordered_map>
#endif
using namespace std;

#if first

// ��Ʈ����ŷ, ��Ʈ��ŷ
vector<int> cnt;				// ��Ʈ����ŷ�ؼ� ������� �ֹ��� �丮�� ����
vector<int> chkDepth;			// course ���͸� idx - val�� val - idx����� �ٲ� �迭
vector<vector<int>> temp;		// idx���� ����� �ڽ� �丮�� idx�� ���ڷ� �����ϴ� �ӽ� �迭
vector<int> maxLen;				// course�� �ִ� ��� Ƚ��

inline void FillCnt(const vector<string>& _orders)
{

	/*
	
	�ֹ��� �丮�� ��Ʈ����ŷ�ؼ� ���ڷ� ��ȯ�ϰ�
	cnt �迭�� ����
	*/
	for (const string& order : _orders)
	{

		int add = 0;
		for (const char c : order)
		{

			add |= 1 << (c - 'A');
		}

		cnt.push_back(add);
	}
}

inline void ChkDepth(vector<int>& _course)
{

	/*
	
	������ ��ǰ�޴� ������ Ȯ���ϴ� chkDepth�迭 ä���
	_couse[idx] = val ���踦
	chkDepth[val] = idx�� �ٲ۴�
	*/
	chkDepth.resize(11, -1);

	for (int i = 0; i < _course.size(); i++)
	{

		chkDepth[_course[i]] = i;
	}
}

inline void DFS(int _depth, int _cur, int _prev, int _escape)
{

	/*
	
	��Ʈ��ŷ���� 
	������ �Ǵ� �ڽ��丮 ã��
	*/

	// �� �̻� Ž���� �ʿ� ����
	if (_depth == _escape) return;

	// ��� ����
	int match = 0;

	// �޴��� ��� 1�� ���ԵǾ��� ������ ����
	if (_depth)
	{

		for (int n : cnt)
		{

			if ((n & _cur) == _cur) match++;
		}

		// �ش� �޴����� ��Ī�Ǵ°� 2�� ���ϸ� �� Ž���� �ʿ� ����
		// ��Ḧ �÷����� ���� ������ ���� ���ϱ� �����̴�
		if (match < 2) return;
	}

	// �ڽ��丮�� ���� ��ǰ�޴� ������ 
	// ���ǿ� �����ϴ� Ƚ������ Ȯ��
	int idx = chkDepth[_depth];
	if (idx != -1)
	{

		// �����ϴ� �ִ� ����� ���ŵǴ� ���
		if (maxLen[idx] < match)
		{

			// ���� ������ �ʿ���⿡ ������
			temp[idx].clear();
			temp[idx].push_back(_cur);
			maxLen[idx] = match;
		}
		// ���� ���� ���� �丮�� �߰�
		else if (maxLen[idx] == match) temp[idx].push_back(_cur);
	}

	// ���� �ڽ� �丮 Ȯ��
	for (int i = _prev; i < 26; i++)
	{

		DFS(_depth + 1, _cur | (1 << i), i + 1, _escape);
	}
}

inline void IntToStr(int _num, string& _str)
{

	/*
	
	���ڸ� ���ڿ���
	���ڷ� �����߱⿡ ���ڿ��� �ٲ���� �Ѵ�
	*/
	_str.clear();

	for (int i = 0; i < 26; i++)
	{

		if (_num & (1 << i)) _str.push_back((char)(i + 'A'));
	}
}
#else

unordered_map<string, int> combi;		// �ڽ��丮, �����ϴ� ��� ��

inline void DFS(string& _order, int _len, string _temp, int _prev)
{

	/*
	
	�ֹ��� ����� ���� len�� ���� ã��
	*/
	if (_temp.length() == _len)
	{

		combi[_temp]++;
		return;
	}

	for (int i = _prev; i < _order.length(); i++)
	{

		DFS(_order, _len, _temp + _order[i], i + 1);
	}
}
#endif

vector<string> solution(vector<string> _orders, vector<int> _course)
{

	vector<string> answer;

#if first

	FillCnt(_orders);
	ChkDepth(_course);

	temp.resize(_course.size(), vector<int>());
	maxLen.resize(_course.back(), 0);

	DFS(0, 0, 0, _course.back() + 1);

	string str;
	for (vector<int>& arr : temp)
	{

		for (int num : arr)
		{

			IntToStr(num, str);
			answer.push_back(str);
		}
	}
#else

	for (string& order : _orders)
	{

		// �޴� ���ĺ� ������ ����
		sort(order.begin(), order.end());
	}

	for (int len : _course)
	{

		// ���� ������ �޴� ����
		combi.clear();

		for (string& order : _orders)
		{

			// order���� ���� len�� �ڽ� �丮 ã�´�
			// �丮�� ���� �����ϴ� ��� �ּ� 1���� ����
			DFS(order, len, "", 0);
		}

		// �����ϴ� ����� �ִ� ��
		int maxCnt = 0;
		for (pair<string, int> ele : combi)
		{

			maxCnt = max(maxCnt, ele.second);
		}

		// 2�� �̻��� �ʼ��̹Ƿ� 2�� �̸��̸� �ѱ��
		if (maxCnt < 2) continue;

		for (pair<string, int> ele: combi)
		{

			// �ش� �޴��� �ִ밪 �޴� answer�� ����
			if (combi[ele.first] == maxCnt) answer.push_back(ele.first);
		}
	}
#endif

	// ��ȯ ���� ���߱�
	sort(answer.begin(), answer.end());

	return answer;
}