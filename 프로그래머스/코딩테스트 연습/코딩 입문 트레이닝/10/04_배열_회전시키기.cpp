#include <vector>
#include <string>
#include <algorithm>


/*
��¥ : 2024. 3. 12
�̸� : �輺��
���� : �迭 ȸ����Ű��
	������ ��� �迭 numbers�� ���ڿ� direction��
	�Ű������� �־�����

	�迭 numbers ���Ҹ� direction �������� ��ĭ��
	ȸ����Ų �迭�� return �ϴ� solution �Լ��� ����

	direction�� left�� right�� �־�����
*/

using namespace std;

vector<int> solution(vector<int> _numbers, string _direction) 
{

	// vector<int> answer;
	// answer.reserve(_numbers.size());
	vector<int> answer = _numbers;

	if (_direction == "left")
	{

		// ���ҵ��� swap�ϸ鼭 ȸ���Ѵ�
		// �ϳ��� swap�ϱ⿡ �ſ� ��ȿ�����̴�
		// ���� 1ĭ �̵�
		// begin() + a : �������� aĭ �̵�
		rotate(answer.begin(), answer.begin() + 1, answer.end());

		/*
		for (int i = 1; i < _numbers.size(); i++)
		{

			answer.push_back(_numbers[i]);
		}
		answer.push_back(_numbers[0]);
		*/

	}
	else 
	{

		// ������ 1ĭ �̵�
		// end() - a : ������ aĭ �̵�
		rotate(answer.begin(), answer.end() - 1, answer.end());
		/*
		answer.push_back(_numbers.back());
		for (int i = 0; i < _numbers.size() - 1; i++)
		{

			answer.push_back(_numbers[i]);
		}
		*/
	}

	return answer;
}