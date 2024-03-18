#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 18
�̸� : �輺��
���� : �迭�� ���絵
	���� ������ ������ �� �迭�� �󸶳� 
	�������� Ȯ���Ϸ����Ѵ�
	
	���ڿ� �迭 s1�� s2�� �־��� ��,
	���� ������ ������
	return �ϵ��� solution �Լ��� ����

	�ߺ��� ���Ҹ� ���� �ʴ´�
*/

using namespace std;

int solution(vector<string> _s1, vector<string> _s2)
{

	int answer = 0;

	// ������ + �� ������ �˰��� ����
	sort(_s1.begin(), _s1.end());
	sort(_s2.begin(), _s2.end());

	int ptr1 = 0;
	int ptr2 = 0;
	
	int max1 = _s1.size();
	int max2 = _s2.size();

	while (ptr1 < max1 && ptr2 < max2)
	{

		// �ߺ� ����� ��
		// ���� ���ҽ��� �ִ밹���� ���ϴ� ������ �ذ��ߴ�
		if (_s1[ptr1] == _s2[ptr2]) ptr1++, ptr2++, answer++;
		else if (_s1[ptr1] < _s2[ptr2]) ptr1++;
		else ptr2++;
	}

	return answer;
}