#include <vector>

/*
��¥ : 2024. 2. 11
�̸� : �輺��
���� : ���ҵ��� ���� ��
	������ ��� ����Ʈ�� �־��� ��, ��� ���ҵ��� ���� ������ ū�� Ȥ�� ���� ū�� ���ؼ�
	���� ũ�� 0�� ���� ������ ũ�� 1�� ����ϴ� �Լ� �����

	���� ���� ���־�����
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;

	int calc1 = 1;		// �� ����
	int	calc2 = 0;		// �� ����

	for (const int c : _num_list) 
	{

		calc1 *= c;
		calc2 += c;
	}

	calc2 *= calc2;
	answer = calc1 < calc2;
	return answer;
}