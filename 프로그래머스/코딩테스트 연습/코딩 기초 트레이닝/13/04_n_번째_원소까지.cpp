#include <vector>

/*
��¥ : 2024. 2. 19
�̸� : �輺��
���� : n ��° ���ұ���
	���� ����Ʈ num_list�� ���� n�� �־��� ��, 
	num_list�� ù ��° ���Һ��� n��° ���ұ�����
	��� ���Ҹ� ���� ����Ʈ�� return �ϴ� solution �Լ� ����
*/
using namespace std;

vector<int> solution(vector<int> _num_list, int _n)
{

	vector<int> answer;

	answer.assign(_num_list.begin(), _num_list.begin() + _n);
	return answer;
}