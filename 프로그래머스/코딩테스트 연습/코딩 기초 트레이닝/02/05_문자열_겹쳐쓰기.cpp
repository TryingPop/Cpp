#include <string>


/*
��¥ : 2024. 2. 8
�̸� : �輺��
���� : ���ڿ� ���ľ���
	���ڿ� ��ü
*/

using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
	string answer = "";
#if !other

	answer = my_string.replace(s, overwrite_string.size(), overwrite_string);
#else

{

	answer = my_string;
	int i = 0;
	for (const char c : overwrite_string)
	{

		answer[s + i++] = c;
	}

// �ٸ� ��� Ǯ��

#endif
	return answer;
}
