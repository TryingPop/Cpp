/*
��¥ : 2024. 6. 11
�̸� : �輺��
���� : JadenCase ���ڿ� �����
	JadenCase�� ��� �ܾ��� ù ���ڰ� �빮���̰�,
	�� �̿��� ���ĺ��� �ҹ����� ���ڿ�

	��, ù ���ڰ� ���ĺ��� �ƴ� ������
	�̾����� ���ĺ��� �ҹ��ڷ� ���� �ȴ�

	���ڿ� s�� �־����� ��, s�� JadenCase�� �ٲ�
	���ڿ��� return �ϴ� solution �Լ� ����

	s�� ���ĺ��� ����, ���� ���ڷ� �̷�����
	���ڴ� ù ���ڷθ� ���´�
	���ڷθ� �̷���� �ܾ�� ����
	���� ���ڰ� �����ؼ� ���� �� �ִ�

	3people unFollowed me
	3people Unfollowed Me
	�� �ٲ���Ѵ�
*/

#include <string>
using namespace std;

string solution(string _s)
{

	string answer;
	answer.reserve(_s.length());

	bool isUp = true;
	for (char c : _s)
	{

#if first
		if ('A' <= c && c <= 'Z')
		{

			if (!isUp) c += 'a' - 'A';
			else isUp = false;
		}
		else if ('a' <= c && c <= 'z')
		{

			if (isUp)
			{

				isUp = false;
				c -= 'A' - 'a';
			}
		}
		else if (c == ' ') isUp = true;
		else if (isUp) isUp = false;
#else

		if (isUp)
		{

			if ('a' <= c && c <= 'z') c += 'A' - 'a';
			if (c != ' ') isUp = false;
		}
		else
		{

			if ('A' <= c && c <= 'Z') c += 'a' - 'A';
			else if (c == ' ') isUp = true;
		}
#endif
		answer.push_back(c);
	}

	return answer;
}