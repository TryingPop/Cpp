#include <string>
#include <vector>

/*
��¥ : 2024. 3. 21
�̸� : �輺��
���� : 7�� ����
	���� �迭 array�� �Ű������� �־��� ��,
	7�� �� � �ִ��� return �ϵ���
	solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _array) 
{

	int answer;

	for (const int i : _array)
	{

		string numStr = to_string(i);

		for (const char c : numStr)
		{

			if (c == '7') answer++;
		}
	}

	return answer;
}