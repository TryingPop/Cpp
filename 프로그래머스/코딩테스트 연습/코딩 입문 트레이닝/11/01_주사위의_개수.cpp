#include <vector>

/*
��¥ : 2024. 3. 13
�̸� : �輺��
���� : �ֻ����� ����
	����, ����, ���̰� ����Ǿ��� �ִ�
	������ �迭 box��

	������ü �ֻ��� �𼭸� ������ ���� n��
	�Ű������� �־��� ��,

	���ڿ� �� �� �ִ� �ֻ����� �ִ� ������ 
	return �ϴ� solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _box, int _n)
{

	int answer = _box[0] / _n;
	answer *= _box[1] / _n;
	answer *= _box[2] / _n;

	return answer;
}