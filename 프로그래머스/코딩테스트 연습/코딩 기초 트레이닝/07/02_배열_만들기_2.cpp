#include <vector>
#include <string>
#include <cmath>

/*
��¥ : 2024. 2. 13
�̸� : �輺��
���� : �迭 ����� 2
	����l�� r�� �־����� ��, l�̻� r������ ���� �߿��� ���� "0"�� "5"�θ�
	�̷���� ��� ������ ������������ ������ �迭�� return�ϴ� soltuion �Լ� �����
	���� �׷��� ������ ���ٸ� -1�� ��� �迭�� return

	���� ������ 100���̱⿡ �׳� �����ϰ� for���� ���ȴ�
	���� ���� ������ 1000�� �̻��̸� ���� ã�� ����� �̿����� ���̴�
*/

using namespace std;

vector<int> solution(int _l, int _r)
{

	vector<int> answer;
#if first
	for (int i = _l; i <= _r; i++) 
	{

		string str = to_string(i);
		bool chk = true;
		for (int j = 0; j < str.length(); j++)
		{

			if (str[j] == '5' || str[j] == '0') continue;
			
			chk = false;
			break;
		}

		if (chk) answer.push_back(i);
	}
	if (answer.empty()) answer.push_back(-1);
#else

	{

		vector<string> calc;
		vector<string> temp;
		// 2 ^ 7�� �ڸ���ŭ ���� Ȯ��! ( 2^0 + 2^1 + ... + 2^6)
		// cmath �ҷ��;� pow�� �ҷ��� �� �ִ�
		calc.reserve(pow(2, 7));
		temp.reserve(pow(2, 7));
		calc.push_back("");

		for (int i = 0; i < 6; i++) 
		{

			for (int j = 0; j < calc.size(); j++) 
			{

				temp.push_back(calc[i] + "0");
				temp.push_back(calc[i] + "5");
			}

			calc = temp;
			temp.clear();
		}

		for (int i = 0; i < calc.size(); i++) 
		{

			int chk = stoi(calc[i]);
			if (chk >= _l && chk <= _r) answer.push_back(chk);
		}
	}


#endif


	return answer;
}