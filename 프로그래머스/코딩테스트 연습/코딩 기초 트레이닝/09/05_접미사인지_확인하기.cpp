#include <vector>
#include <string>

/*
��¥ : 2024. 2. 15
�̸� : �輺��
���� : ���̻����� Ȯ���ϱ�
	banana�� ���̻��
		banana
		anana
		nana
		ana
		na
		a

	���ڿ� my_string�� is_suffix�� �־��� ��,
	is_suffix�� my_string�� ���̻��� 1, �ƴϸ� 0�� ��ȯ�ϴ� �Լ� ����
*/

using namespace std;

int solution(string _my_string, string _is_suffix)
{

	int answer = 0;
	
	if (_my_string.length() < _is_suffix.length()) return answer;
	/*
	for (int i = 1; i < len; i++)
	{

		if (chk == _is_suffix) 
		{

			answer = 1;
			break;
		}
		chk.erase(0, 1);
	}
	*/

	string chk = _my_string.substr(_my_string.length() - _is_suffix.length());
	answer = chk == _is_suffix;
	return answer;
}