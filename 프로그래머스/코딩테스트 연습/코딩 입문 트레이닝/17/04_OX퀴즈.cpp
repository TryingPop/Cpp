#include <string>
#include <vector>
#include <sstream>

/*
��¥ : 2024. 3. 19
�̸� : �輺��
���� : OX����
	����, ���� ���ĵ���	X [������] Y = Z ���·�
	����ִ� ���ڿ� �迭 quiz�� �Ű������� �־�����

	������ �Ǵٸ� O�� Ʋ���ٸ� X�� ������� ����
	�迭�� return �ϵ��� solution �Լ��� ����

	���� ��ȣ�� ���� ���̿��� �׻� �ϳ��� ������ ����
	���̳ʽ� ��ȣ�� ���� ���̿��� ������ ����

	���� ������ ��� int���� �ִ�
	X, Y, Z�� ���� 0���� 9�� �̷���� ���ڸ�
	�� �տ� ���̳ʽ� ��ȣ�� ���� �� �ְ�
	�̴� ������ �ǹ�

	X, Y, Z���� 0�� �����ϰ�� 0���� �����ϴ� ���ڴ� ����
	�����ڴ� +, - �� �ϳ���
*/

using namespace std;

vector<string> solution(vector<string> _quiz)
{

	vector<string> answer;
	answer.reserve(_quiz.size());

#if other

	stringstream ss;
	for (const string str : _quiz)
	{

		int f, b, a;
		char op;
		char equal;

		bool isWrong;
		// stringstream ss;
		ss.clear();
		ss.str(str);

		ss >> f >> op >> b >> equal >> a;


		if (op == '+') isWrong = f + b != a;
		else isWrong = f - b != a;

		if (isWrong) answer.push_back("X");
		else answer.push_back("O");
	}
#endif

	for (const string eval : _quiz)
	{

		// �Է� ���� ����
		bool isF = false;		// ù ��° ���� �Է� �޾Ҵ���?
		bool isO = false;		// ������ �Է� �޾Ҵ���?
		bool isB = false;		// �� ��° ���� �Է� �޾Ҵ���?
		bool isE = false;		// �̲� �Է� �޾Ҵ���?

		// ���� 
		int f = 0;				// �Ǿ�
		int b = 0;				// �߰�
		int a = 0;				// ����

		// +, -
		bool opPlus = true;		// �����ڰ� +?
		bool nPlus = true;		// ���ڰ� ���

		for (const char c : eval)
		{

			if (c == ' ')
			{

				if (!isF)
				{

					isF = true;
					f = nPlus ? f : -f;
					nPlus = true;
				}
				else if (!isO) isO = true;
				else if (!isB)
				{

					isB = true;
					b = nPlus ? b : -b;
					nPlus = true;
				}
				else if (!isE) isE = true;
			}
			// + ���� Ȯ��
			else if (isF && !isO) opPlus = c == '+';
			// = ����
			else if (isB && !isE) continue;
			else 
			{

				// ���� �Է� �޴� ���
				if (c == '-') nPlus = false;
				else if (!isF) f = f * 10 + c - '0';
				else if (!isB) b = b * 10 + c - '0';
				else a = a * 10 + c - '0';
			}
		}

		a = nPlus ? a : -a;

		// ���� ��� Ȯ��
		if (opPlus)
		{

			if (f + b == a) answer.push_back("O");
			else answer.push_back("X");
		}
		else 
		{

			if (f - b == a) answer.push_back("O");
			else answer.push_back("X");
		}
	}

	return answer;
}