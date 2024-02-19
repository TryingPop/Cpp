#include <string>
#include <vector>

/*
��¥ : 2024. 2. 19
�̸� : �輺��
���� : ���� ������
	���ڿ� ����Ʈ str_list���� "u", "d", "l", "r"�� �̷���� ����Ʈ�̴�
	str_list���� "l"�� "r" �� ���� ������ ���ڿ��� "l"�̶��
	�ش� ���ڿ��� �������� ���ʿ� �ִ� ���ڿ����� ������� ���� ����Ʈ��,
	���� ������ ���ڿ��� "r"�̶�� �ش� ���ڿ��� �������� �����ʿ� �ִ� ���ڿ����� ������� ����
	����Ʈ�� return �ϵ��� solution �Լ��� ����
	"l", "r"�� ���ٸ� �� ����Ʈ�� ��ȯ
*/

using namespace std;

vector<string> solution(vector<string> _str_list)
{

	vector<string> answer;

	int pos = -1;
	bool isL = false;
	for (int i = 0; i < _str_list.size(); i++)
	{

		if (_str_list[i] == "r")
		{

			isL = false;
			pos = i;
			break;
		}
		else if (_str_list[i] == "l")
		{

			isL = true;
			pos = i;
			break;
		}
	}

	if (pos != -1)
	{

		if (isL)
		{

			for (int i = 0; i < pos; i++)
			{

				answer.push_back(_str_list[i]);
			}

			// answer.assign(_str_list.begin(), _str_list.begin() + pos);
		}
		else 
		{

			for (int i = pos + 1; i < _str_list.size(); i++)
			{

				answer.push_back(_str_list[i]);
			}

			// answer.assign(_str_list.begin() + pos + 1, _str_list.end());
		}
	}
	return answer;
}
