#include <vector>
#include <algorithm>

#include <map>

/*
��¥ : 2024. 3. 10
�̸� : �輺��
���� : ���� ���� ���ϱ�
	���޵��� ��Ÿ���� ���� �迭 emergency�� �Ű������� �־��� ��,
	���޵��� ���� ������� ���� ������ ���� �迭��
	return �ϴ� solution �Լ� ����

	_emergency�� ���޵��� 100������ ���̾ƴ� �����̰� �ߺ��� ���� ����
*/

using namespace std;

vector<int> solution(vector<int> _emergency)
{

	vector<int> answer(_emergency.size());

	vector<int> varToIdx(101, -1);

	for (int i = 0; i < _emergency.size(); i++) 
	{

		varToIdx[_emergency[i]] = i;
	}

	sort(_emergency.begin(), _emergency.end(), greater<int>());

	for (int i = 0; i < _emergency.size(); i++)
	{

		answer[varToIdx[_emergency[i]]] = i + 1;
	}

	/*
	map<int, int> temp = map<int, int>();
	
	for (const int i : _emergency)
	{

		temp[i];
	}

	int order = _emergency.size();

	// ���� Ű������ �˾Ƽ� �������� ���� ���ش�
	// ���� ��ȯ�ϱ⿡ �ּҷ� �޾ƿ´�
	for (pair<const int, int>& ptr : temp) 
	{

		ptr.second = order--;
	}

	for (const int i : _emergency) 
	{

		answer.push_back(temp[i]);
	}
	*/
	
	return answer;
}