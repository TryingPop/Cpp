#include <vector>
#include <algorithm>
#define DIFF 5

/*
��¥ : 2024. 2. 27
�̸� : �輺��
���� : �ڿ��� 5�� ����
	������ �̷���� ����Ʈ num_list�� �־�����
	num_list���� ���� ���� 5���� ���� ������ ������
	������������ ���� ����Ʈ�� return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<int> _num_list)
{

	vector<int> answer;
	answer.reserve(_num_list.size() - DIFF);

	vector<int> temp = _num_list;
	sort(temp.begin(), temp.end());

	answer.assign(temp.begin() + 5, temp.end());
	return answer;
}