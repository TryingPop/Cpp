#include <string>
#include <vector>

/*
��¥ : 2024. 2. 17
�̸� : �輺��
���� : ī��Ʈ �ٿ�
	���� start_num�� end_num�� �־��� ��,
	start_num���� end_num���� 1�� �����ϴ� ������ ���ʷ� ����
	����Ʈ�� return�ϴ� �Լ� ����
*/

using namespace std;

vector<int> solution(int _start, int _end_num)
{

	vector<int> answer;
	answer.reserve(_start - _end_num + 1);

	for (int i = _start; i >= _end_num; i--) 
	{

		answer.push_back(i);
	}

	return answer;
}