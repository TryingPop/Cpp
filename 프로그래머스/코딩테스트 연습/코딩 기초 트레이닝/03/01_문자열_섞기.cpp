#include <string>
#include <vector>

/*
��¥ : 2024. 2. 9
�̸� : �輺��
���� : ���ڿ� ����
	���̰� ���� �� ���� ���ڿ��� �ϳ��� ����ϴ� �޼��� �������Ѵ�
	
	aaaaa bbbbb
	ababababab


	���Ϳ��� ������Ƽ�� ptr, size, capacity���� ����
	push_back�� O(1) << �ڿ� �ֱ⸸ �ؼ�
	push_front�� O(n) << �տ� �ְ� 1ĭ�� �̵��ϴ� ����

	���� ����� �Ҵ��ϰ� �ڿ� �����Ѵ�

	https://bconfiden2.tistory.com/4

	string Ŭ�������� null ���ڰ� ����
	��ü������ length�� ���� �ֱ� �����̴�
*/
using namespace std;

string solution(string str1, string str2)
{

	string answer = "";
	// ������ Ȯ��
	// answer.capacity();
	// �̸� ũ�� �Ҵ�
	// �׷��� reserve�ȿ� * 2�� �ϸ� 8����Ʈ ĳ�����Ѵٰ� vs���� �˸���;
	answer.reserve(str1.size() + str2.size());

	// str1.length(); ���ص� �ȴ�
	for (int i = 0; i < str1.size(); i++) 
	{


		// answer += str1[i];
		answer.push_back(str1[i]);
		// answer += str2[i];
		answer.push_back(str2[i]);
	}
	return answer;
}