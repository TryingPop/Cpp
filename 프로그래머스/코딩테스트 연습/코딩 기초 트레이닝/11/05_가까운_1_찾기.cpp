#include <vector>

/*
��¥ : 2024. 2. 17
�̸� : �輺��
���� : ����� 1 ã��
	���� �迭 arr�� �־�����
	�̶� arr�� ���Ҵ� 1 �Ǵ� 0
	���� idx�� �־����� ��, idx�̻��� �ε����� ���� �迭�� ���� 1�� 
	���� ���� �ε����� ã�Ƽ� ��ȯ�ϴ� solution �Լ� ����

	���� ���ٸ� -1 ��ȯ
*/

using namespace std;

int solution(vector<int> _arr, int _idx)
{

	int answer = -1;

	for (int i = _idx; i < _arr.size(); i++)
	{

		if (_arr[i] == 1) 
		{ 
			
			answer = i; 
			break;
		}
	}

	return answer;
}