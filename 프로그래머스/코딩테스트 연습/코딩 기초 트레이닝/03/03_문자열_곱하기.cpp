#include <string>
#include <vector>

/*
��¥ : 2024. 2. 9
�̸� : �輺��
���� : ���ڿ� ���ϱ�
	���ڿ� my_string�� ���� k�� �־��� ��,
	my_string�� k�� �ݺ��ϴ� ���ڿ��� return�ϰ� �ϴ� solution �Լ� �ۼ�

	my_string�� ���̴� 100���ϰ�, ���ĺ� �ҹ��ڷ� �̷���� ���ڿ�
	k�� 100������ �ڿ���

	input
	aaa 5

	answer
	aaaaaaaaaaaaaaa
*/

using namespace std;

string solution(string my_string, int k)
{

	string answer = "";
	//	int size = my_string.size() * k;
	//	answer.reserve(size);
	answer.reserve(my_string.size() * k);

	for (int i = 0; i < k; i++)
	{

		answer.append(my_string);
	}

	return answer;
}