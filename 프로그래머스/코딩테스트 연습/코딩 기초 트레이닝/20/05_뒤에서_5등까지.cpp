#include <vector>
#include <algorithm>
#define LEN 5

/*
��¥ : 2024. 2. 26
�̸� : �輺��
���� : �ڿ��� 5�����
	������ �̷���� ����Ʈ num_list�� �־�����
	num_list���� ���� ���� 5���� ���� ������������ ����
	����Ʈ�� return �ϵ��� solution �Լ��� ����
*/
using namespace std;

vector<int> solution(vector<int> _num_list)
{

	vector<int> answer;
	answer.reserve(LEN);

	vector<int> sortArr = _num_list;

	// ����
	sort(sortArr.begin(), sortArr.end());

	// ���� ���� 5�� �Ҵ�
	answer.assign(sortArr.begin(), sortArr.begin() + LEN);

	return answer;
}