#include <vector>

/*
��¥ : 2024. 3. 10
�̸� : �輺��
���� : �迭 �ڸ���
	���� �迭 numbers�� ���� num1, num2�� 
	�Ű������� �־��� ��,
	numbers�� num1��° �ε������� 
	num2��° �ε������� �ڸ� ���� �迭��
	return �ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<int> _numbers, int _num1, int _num2)
{

	vector<int> answer;
	answer.assign(_numbers.begin() + _num1, _numbers.begin() + _num2 + 1);
	return answer;
}