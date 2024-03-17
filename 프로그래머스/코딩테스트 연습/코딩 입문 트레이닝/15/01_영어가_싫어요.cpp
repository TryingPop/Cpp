#include <string>
#include <vector>
#include <map>

/*
��¥ : 2024. 3. 17
�̸� : �輺��
���� : ��� �Ⱦ��
	����� ǥ��Ǿ� �ִ� ���ڷ� �ٲٷ��� �Ѵ�
	���ڿ� numbers�� �Ű������� �־��� ��,
	numbers�� ������ �ٲ� return �ϵ��� solution �Լ� ����

	numbers�� �ҹ��ڷ� �����Ǿ� �ִ�
*/

using namespace std;

long long solution(string _numbers)
{

	long long answer = 0;
#if other

	vector<string> numStr =
		{

			"zero", "one", "two",
			"three", "four", "five",
			"six", "seven", "eight", "nine"
		};

	// ã�� �ε���
	int calc;

	for (int i = 0; i < numStr.size(); i++)
	{

		// numStr�� �ܾ ��� ã�� ���ڷ� �ٲ۴�
		// �ش� ������ find�� �ε����� ã��
		while ((calc = _numbers.find(numStr[i])) != string::npos)
		{

			// �ش� ���ڸ� ���ڷ� ����
			_numbers.replace(calc, numStr[i].size(), to_string(i));
		}
	}

	// long long ���·� ����
	answer = stoll(numStr);
	return answer;
#endif
	string numStr = "";
	numStr.reserve(50);

	// --------------------
	// ��� - ī�� �˰���
	// ����ϰ� ����
	// 
	// �ش� �κ��� replace �޼��带 �̿��� �ذ� �����ϴ�
	// --------------------

	// 3�ڸ��� ���� �����ǵ�, ������ �ܾ�κ�
	// zero �� 4���ε� 3���� ������ 1�� �����ϴٴ� �ǹ̿��� -1�̴�
	// ���������� three�� 5���ε� 3���� ������ 2�� �����ϴٴ� �ǹ̷� -2�̴�
	vector<int> rlen = { -1, 0, 0, -2, -1, -1, 0, -2, -2, -1 };

	// ���� �ܾ ���ڷ� �����ؼ� �ش� ���ڿ� ��ġ�ϴ��� Ȯ���ϴ°� �ֵ� �����̴�
	// �ҹ��ڸ� �־��� �ְ� ��� zer, one, two, ... nin�� ��� �ٸ���
	// �浹 ���ϴ� ������ �ڿ����� mod�� ������ �ȴ�
	// ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, 26�̻��� ������ ���� �浹 �ȳ���
	// �׸��� 3�ڸ� �ۿ� �ȵǾ� �׳� �ʱ⿣ 128�� �ʰ��ϴ� �Ҽ� 131�� ��� Ǯ������
	// �׷��� 2�� ��Ƶ� Ǯ�̿� �浹 ���Ͼ�� 2�� ��Ҵ�
	// �浹 �Ͼ�� mod ���ڸ� �ٲٸ� �ȴ�
	int mod = 2;
	map<int, int> kTon = map<int, int>();
	{

		int sqMod = mod * mod;
		kTon['z' * sqMod + 'e' * mod + 'r'] = 0;
		kTon['o' * sqMod + 'n' * mod + 'e'] = 1;
		kTon['t' * sqMod + 'w' * mod + 'o'] = 2;
		kTon['t' * sqMod + 'h' * mod + 'r'] = 3;
		kTon['f' * sqMod + 'o' * mod + 'u'] = 4;
		kTon['f' * sqMod + 'i' * mod + 'v'] = 5;
		kTon['s' * sqMod + 'i' * mod + 'x'] = 6;
		kTon['s' * sqMod + 'e' * mod + 'v'] = 7;
		kTon['e' * sqMod + 'i' * mod + 'g'] = 8;
		kTon['n' * sqMod + 'i' * mod + 'n'] = 9;
	}

	// Ű �� ����
	int key = 0;
	// ���� �ڸ��� ����
	int chk = 0;

	for (const char c : _numbers)
	{

		// ������ �κ� ä���
		if (chk < 0) chk++;
		else if (chk < 3)
		{

			// 3�� �д´�
			key = key * mod + c;
			chk++;
		}

		if (chk == 3)
		{

			// Ű�� �ϼ��Ǿ��� �� �� ����
			int val = kTon[key];
			numStr.push_back(val + '0');
			key = 0;
			chk = rlen[val];
		}
	}

	// ���� numStr�� ���ڷ� �ٲ۴�
	for (const char c : numStr)
	{

		answer = answer * 10 + c - '0';
	}

	return answer;
}