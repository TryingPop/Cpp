#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : �迭 ������
	������ ��� �ִ� �迭 num_list�� �Ű������� �־��� ��,
	num_list�� ������ ������ �Ųٷ� ������ �迭��
	return�ϴ� solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _num_list) 
{

	vector<int> answer = _num_list;

	// ������
	reverse(answer.begin(), answer.end());
	return answer;
}