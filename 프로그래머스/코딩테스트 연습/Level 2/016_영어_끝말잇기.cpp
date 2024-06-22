/*
��¥ : 2024. 6. 23
�̸� : �輺��
���� : ���� ���� �ձ�
	1���� n���� ��ȣ�� �پ��ִ� n���� �����
	�����ձ⸦ �ϰ� �ִ�

	�����ձ� ��Ģ�� ������ ����
		1. 1�� ��ȣ���� ������� �� ����� ���ʴ�� �ܾ ���Ѵ�
		2. ������ ����� �ܾ ���� �������� �ٽ� 1������ �����Ѵ�
		3. �ջ���� ���� �ܾ��� ������ ���ڷ� �����ϴ� �ܾ ���ؾ� �Ѵ�
		4. ������ �����ߴ� �ܾ�� ����� �� ����

	����� �� n�� ������� ������� ���� �ܾ� words�� 
	�Ű������� �־��� ��, ���� ���� Ż���ϴ� ����� ��ȣ��
	�� ����� �ڽ��� �� ��° ���ʿ��� Ż���ϴ����� ���ؼ�
	return �ϴ� solution �Լ��� ����

	���� �־��� �ܾ��� Ż���ڰ� ������ �ʴ´ٸ� 
	{ 0, 0 }�� return

	��� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ִ�
	n�� 2 �̻� 10������ �ڿ���
	
	words�� ���̴� n�̻� 100�����̰�
	����(�ܾ�)���� ���̴� 2 �̻� 50����

	parameter
	2, { "hello", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" }


	return
	{ 3, 3 }
*/

#include <map>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(int _n, vector<string> _words)
{

	vector<int> answer(2, 0);

	string before = _words[0];
	map<string, bool> use;
	use[before] = true;

	for (int i = 1; i < _words.size(); i++)
	{

		if (_words[i][0] != before.back() || use[_words[i]])
		{

			// ���� ������ ���� ������ ���� �ȸ´� ��쳪 �̹� ����� ���ڸ� Ż��
			answer[0] = 1 + (i % _n);
			answer[1] = 1 + (i / _n);
			break;
		}

		// �������� ���� �� ����� ���� ����
		before = _words[i];
		use[before] = true;
	}

	return answer;
}