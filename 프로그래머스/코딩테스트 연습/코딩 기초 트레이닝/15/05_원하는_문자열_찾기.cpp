#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 2. 21
�̸� : �輺��
���� : ���ϴ� ���ڿ� ã��
	���ĺ����� �̷���� ���ڿ� myString�� pat�� �־�����
	myString�� ���ӵ� �κ� ���ڿ� �� pat�� �����ϸ� 1��
	�׷��� ������ 0�� return�ϴ� solution �Լ� ����

	��, ���ĺ��� ��ҹ��ڴ� �������� �ʴ´�
*/

using namespace std;

int solution(string _myString, string _pat)
{

	int answer = 0;

	string find = _pat;
	string chk = _myString;
#if other
	{

		// �ҹ��� ��ȯ
		int calc = 'a' - 'A';

		for (int i = 0; i < find.length(); i++) 
		{

			if (find[i] < 'a') find[i] += calc;
		}

		for (int i = 0; i < chk.length(); i++) 
		{

			if (chk[i] < 'a') chk[i] += calc;
		}
	}

	// kmp �˰���
	vector<int> kmp;

	kmp.reserve(find.length());

	kmp.push_back(0);

	for (int i = 1; i < find.length(); i++)
	{

		int calc = kmp[i - 1];
		if (find[i] == find[calc])
		{

			kmp.push_back(calc + 1);
		}
		else 
		{

			calc = kmp[calc - 1];
			while (calc != 0)
			{

				if (find[i] == find[calc])
				{

					kmp.push_back(calc + 1);
					break;
				}

				calc = kmp[calc - 1];
			}

			if (calc == 0) kmp.push_back(0);
		}
	}

	int matching = 0;
	for (int i = 0; i < chk.length(); i++)
	{

		
		if (chk[i] == find[matching]) 
		{

			matching++;
		}
		else 
		{

			while (matching > 0)
			{

				matching = kmp[matching - 1];
				if (chk[i] == find[matching])
				{

					matching++;
					break;
				}
			}
		}

		if (matching == find.length())
		{

			answer = 1;
			break;
		}
	}
#else

	// �ø� ��ȯ
	transform(find.begin(), find.end(), find.begin(), ::toupper);
	transform(chk.begin(), chk.end(), chk.begin(), ::toupper);

	// find ���ڿ� ã�´�
	answer = chk.find(find) != string::npos;
#endif

	
	return answer;
}