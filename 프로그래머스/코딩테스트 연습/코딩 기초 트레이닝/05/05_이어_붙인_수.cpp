#include <vector>

/*
��¥ : 2024. 2. 11
�̸� : �輺��
���� : �̾� ���� ��
	������ ��� ����Ʈ _num_list�� �־�����
	Ȧ���� ������� �̾���� ���� ¦���� �̾���� ���� �տ� return�ϴ� �Լ� �����

	����Ʈ ���� ���� 1 ~ 9������ ����!
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;

	int odd = 0;
	int even = 0;
	
	for (const int c : _num_list)
	{

		if (c & 1)
		{ 
			
			odd *= 10;
			odd += c; 
		}
		else 
		{ 
		
			even *= 10;
			even += c; 
		}
	}

	answer = odd + even;
	return answer;
}