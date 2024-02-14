#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 2. 14
�̸� : �輺��
���� : ���ڿ� ���� �� ������
	���ڿ� my_string�� ������ ���� �迭 queries�� �Ű������� �־�����
	queries�� ���Ҵ� { s, e }�� ���·�,
	my_string�� �ε��� x���� �ε��� e������ ��������� �ǹ�
	my_string�� queries�� ����� ������� ó���� ���� ���ڿ��� return �ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _my_string, vector<vector<int>> _queries)
{

	string answer = _my_string;

	for (const vector<int> query : _queries)
	{

		// reverse�Լ�
		// answer�� ���� ���� + query[0]����
		// answer�� query[1] + 1�� �ٷ� �ձ��� �ٲ۴�
		reverse(answer.begin() + query[0], answer.begin() + query[1] + 1);
		/*
		int mid = (query[0] + query[1]) / 2;
		for (int i = query[0]; i <= mid; i++) 
		{

			swap(answer[i], answer[query[0] + query[1] - i]);
		}
		*/
	}

	return answer;
}