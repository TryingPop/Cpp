#include<vector>

/*
��¥ : 2024. 3. 21
�̸� : �輺��
���� : �Ӿ��̺��� Ű ū ���
	���� �迭 array�� Ű height�� �Ű������� �־��� ��,
	height���� ū array�� ������ ������ 
	return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(vector<int> _array, int _height)
{

	int answer = 0;

	for (const int i : _array)
	{

		if (i > _height) answer++;
	}

	return answer;
}