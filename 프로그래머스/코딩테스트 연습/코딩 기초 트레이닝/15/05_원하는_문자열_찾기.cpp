#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 2. 21
이름 : 배성훈
내용 : 원하는 문자열 찾기
	알파벳으로 이루어진 문자열 myString과 pat이 주어진다
	myString의 연속된 부분 문자열 중 pat이 존재하면 1을
	그렇지 않으면 0을 return하는 solution 함수 구현

	단, 알파벳의 대소문자는 구분하지 않는다
*/

using namespace std;

int solution(string _myString, string _pat)
{

	int answer = 0;

	string find = _pat;
	string chk = _myString;
#if other
	{

		// 소문자 변환
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

	// kmp 알고리즘
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

	// 올림 변환
	transform(find.begin(), find.end(), find.begin(), ::toupper);
	transform(chk.begin(), chk.end(), chk.begin(), ::toupper);

	// find 문자열 찾는다
	answer = chk.find(find) != string::npos;
#endif

	
	return answer;
}