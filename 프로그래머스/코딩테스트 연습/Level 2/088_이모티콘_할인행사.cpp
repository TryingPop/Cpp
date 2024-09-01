/*
��¥ : 2024. 9. 1
�̸� : �輺��
���� : �̸�Ƽ�� �������
	īī���忡���� �̸�Ƽ���� ���������� ����� �� �ִ�
	�̸�Ƽ�� �÷��� ���� ������ ���� �ø����� �Ѵ�

	�̸�Ƽ�� ������縦 �ϴµ�,
	��ǥ�� ������ ����

	1. �̸�Ƽ�� �÷��� ���� �����ڸ� �ִ��� �ø��� ��
	2. �̸�Ƽ�� �Ǹž��� �ִ��� �ø��°�

	1�� ��ǥ�� �켱�̸�, 2�� ��ǥ�� �� �����̴�

	�̸�Ƽ�� ���� ���� ������ ���� ������� ����ȴ�
	n���� īī���� ����ڵ��� �̸�Ƽ�� m���� �����Ͽ� �Ǹ��Ѵ�

	�̸�Ƽ�ܸ��� �������� �ٸ� �� ������,
	�������� 10%, 20%, 30%, 40% �� �ϳ��� �����ȴ�

	īī���� ����ڵ��� ������ ���� ������ ���� �̸�Ƽ���� ��ų�
	�̸�Ƽ�� �÷��� ���񽺿� �����Ѵ�

	�� ����ڵ��� �ڽ��� ���ؿ� ���� ���� ���� �̻� �����ϴ�
	�̸�Ƽ���� ��� �����Ѵ�

	�� ����ڵ��� �ڽ��� ���ؿ� ���� 
	�̸�Ƽ�� ���� ����� ���� ���� ���� �̻��� �ȴٸ�,
	�̸�Ƽ�� ���Ÿ� ��� ����ϰ� �̸�Ƽ�� �÷��� ���񽺿� �����Ѵ�

	īī���� ����� n���� ���� ������ ���� 2���� ���� �迭 users,
	�̸�Ƽ�� m���� ������ ���� 1���� ���� �迭 emoticons�� �־��� ��,
	��� ������ �ִ������� �޼����� ���� �̸�Ƽ�� �÷��� ���� ���� ����
	�̸�Ƽ�� ������� 1���� ���� �迭�� ��� return �ϴ� solution �Լ� ����

	users�� ���̴� 100 ������ �ڿ����̰�,
	users�� ���Ҵ� { ����, ���� } ������ �����̴�
	users[i]�� i + 1 �� ���� �����̴�

	���� %�̻��� ������ �ִ� �̸�Ƽ���� ��� �����Ѵٴ� �ǹ��̴�
	������ 40������ �ڿ���

	���� �̻��� ���� �̸�Ƽ�� ���ſ� ����Ѵٸ�,
	�̸�Ƽ�� ���Ÿ� ��� ����ϰ� �÷����� �����Ѵٴ� �ǹ��̴�
	������ 100�� ������ �ڿ����̸� 100 ���� ���� ��������

	emoticons�� ���̴� 7 �����̴�
	emoticons[i]�� i + 1 �� �̸�Ƽ���� ������ �ǹ��Ѵ�

	emoticons�� ���Ҵ� 100�� ������ �ڿ����̰� 100���� ���� ��������


	parameter
	{ { 40, 10000 }, { 25, 10000 } }, { 7000, 9000 }


	return
	{ 1, 5400 }


	sol
	1��, 2���� 40%�� �����ص� �ִ� ���� ������ ���� 1���̴�
	�� �� ������ �ִ��� ì��� ���� 1���� 30% �����ϰ�, 2���� 40% ������ ���
	������ ���� 1���̸�, �ִ� ������ ì��� ����̴�
*/

#include <vector>

using namespace std;

inline int ChkPrice(int _p, int _s)
{

	/*
	
	���� ���
	*/
	return (_p * (100 - _s)) / 100;
}

int join;
int total;

vector<int> sale = { 40, 30, 20, 10 };
vector<int> select;

inline void ChkBuy(vector<vector<int>>& _users, vector<int>& _emoticons)
{

	/*
	
	������ ��, ���� ���
	*/

	int ret1 = 0;
	int ret2 = 0;

	for (vector<int>& user : _users)
	{

		// ���� ���
		int p = 0;
		for (int i = 0; i < select.size(); i++)
		{

			if (sale[select[i]] < user[0]) continue;
			p += ChkPrice(_emoticons[i], sale[select[i]]);
		}

		if (user[1] <= p) ret1++;
		else ret2 += p;
	}

	if (join < ret1)
	{

		join = ret1;
		total = ret2;
	}
	else if (join == ret1 && total < ret2) total = ret2;
}

inline void DFS(vector<vector<int>>& _users, vector<int>& _emoticons, int _depth = 0)
{

	if (_depth == _emoticons.size())
	{

		ChkBuy(_users, _emoticons);
		return;
	}

	for (int i = 0; i < 4; i++)
	{

		select[_depth] = i;
		DFS(_users, _emoticons, _depth + 1);
	}
}

vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons)
{

	/*
	
	���Ʈ����
	4^7 * 100 <= 200��
	*/
	vector<int> answer;
	select.resize(_emoticons.size());

	DFS(_users, _emoticons);

	answer.push_back(join);
	answer.push_back(total);

	return answer;
}