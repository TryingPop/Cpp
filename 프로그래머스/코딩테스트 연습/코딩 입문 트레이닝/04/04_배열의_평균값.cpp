#include <vector>

/*
��¥ : 2024. 3. 8
�̸� : �輺��
���� : �迭�� ��հ�
	���� �迭 numbers�� �Ű������� �־�����
	numbers�� ������ ��հ��� return �ϵ���
	solution �Լ��� ����

	������ �Ҽ��κ��� .0 �Ǵ� .5�̴�
*/

using namespace std;

double solution(vector<int> _numbers)
{

	double answer = 0;

	for (int i : _numbers)
	{

		answer += i;
	}

	answer /= _numbers.size();
	return answer;
}