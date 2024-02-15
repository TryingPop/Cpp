#include <string>
#include <vector>

/*
��¥ : 2024. 2. 15
�̸� : �輺��
���� : �κ� ���ڿ� �̾� �ٿ� ���ڿ� �����
	���̰� ���� ���ڿ� �迭 my_strings�� ������ ���� �迭 parts�� �Ű������� �־�����
	parts[i]�� { s, e }�� �����̰�, my_string[i]�� �ε��� s���� e������ �κй��ڿ��� �ǹ�
	�� my_strings�� ���� parts�� �ش��ϴ� �κ� ���ڿ��� ������� �̾� ���� ���ڿ��� return �ϴ�
	solution �Լ� �����ϱ�
*/

using namespace std;

string solution(vector<string> _my_strings, vector<vector<int>> _parts)
{

	string answer = "";

	for (int i = 0; i < _my_strings.size(); i++)
	{

		/*
		for (int j = _parts[i][0]; j <= _parts[i][1]; j++)
		{

			answer.push_back(_my_strings[i][j]);
		}
		*/

		answer.append(_my_strings[i].substr(_parts[i][0], _parts[i][1] - _parts[i][0] + 1));
	}
	return answer;
}