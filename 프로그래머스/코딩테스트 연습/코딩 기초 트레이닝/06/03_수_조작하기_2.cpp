#include <string>
#include <vector>
#include <map>

/*
��¥ : 2024. 2. 12
�̸� : �輺��
���� : �� �����ϱ� 2
	���� �迭 numLog, ó���� numLog[0]�������� ������
	"w", "s", "a", "d"�� �̷���� ���ڿ��� �Է¹޾� ������ ���� �������Ѵ�
	"w" : ���� 1�� ���Ѵ�
	"s" : ���� 1�� ����
	"d" : ���� 10�� ���Ѵ�
	"a" : ���� 10�� ����

	�׸��� �Ź� ������ �� ������ ������� ����� ���� �迭�� numLog
	numLog[i]�� numLog[0]�κ��� �� i�� ������ ���� ����� ����

	numLog�� ���� ������ ���� �Է¹��� ���ڿ��� return�ϴ� solution �Լ��� �ϼ��ϱ�
	
	���� �����Ұ� ���
*/

using namespace std;

string solution(vector<int> _numLog) 
{

	// �ι��� ����
	string answer = "";
	answer.reserve(_numLog.size());
	int before = _numLog[0];

	map<int, char> m = { { -10, 'a'}, { -1, 's' }, { 1, 'w' }, { 10, 'd' } };
	for (const int c : _numLog)
	{

		int calc = c - before;
		
		answer.push_back(m[calc]);
		/*
		switch (calc)
		{

			case -1:
				answer.push_back('s');
				break;
			case 1:
				answer.push_back('w');
				break;

			case 10:
				answer.push_back('d');
				break;
			case -10:
				answer.push_back('a');
				break;
		}
		*/
		before = c;
	}

	// �� ���� ����
	answer.erase(0, 1);
	return answer;
}