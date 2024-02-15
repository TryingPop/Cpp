#include <string>
#include <vector>
// #include <algorithm>

/*
날짜 : 2024. 2. 15
이름 : 배성훈
내용 : 접미사 배열
	예를들어 banana 문자열의 접미사 배열은
		banana
		anana
		nana
		ana
		na
		a
	와 같다

	문자열 my_string이 주어질 때, my_string의 모든 접미사를 사전순으로 정렬한
	문자열 배열을 return하는 solution 함수를 구현
*/

using namespace std;

int compareTo(string _str1, string _str2)
{

	int len = _str1.length() < _str2.length() ? _str1.length() : _str2.length();

	for (int i = 0; i < len; i++)
	{

		if (_str1[i] != _str2[i]) return _str1[i] - _str2[i];
	}

	return _str1.length() - _str2.length();
}

vector<string> solution(string _my_string)
{

	vector<string> answer;

	int len = _my_string.length();
	answer.reserve(len);

	for (int i = 0; i < len; i++)
	{

		answer.push_back(_my_string.substr(i));
	}

	// sort(answer.begin(), answer.end());

	// QuickSort
	for (int i = 1; i < len; i++) 
	{

		// 큰것을 위로 보내야한다!
		int cur = i;

		while (cur != 0)
		{

			int p = (cur - 1) / 2;

			if (compareTo(answer[cur], answer[p]) > 0)
			{

				swap(answer[cur], answer[p]);
				cur = p;
			}
			else break;
		}
	}

	swap(answer[0], answer[len - 1]);

	for (int i = len - 2; i > 0; i--) 
	{

		int cur = 0;
		while (true)
		{

			int l = cur * 2 + 1;
			int r = cur * 2 + 2;

			if (r <= i)
			{

				if (compareTo(answer[l], answer[r]) > 0 && compareTo(answer[cur], answer[l]) < 0)
				{

					swap(answer[cur], answer[l]);
					cur = l;
				}
				else if (compareTo(answer[cur], answer[r]) < 0)
				{

					swap(answer[cur], answer[r]);
					cur = r;
				}
				else break;
			}
			else if (l <= i)
			{

				if (compareTo(answer[cur], answer[l]) < 0)
				{

					swap(answer[cur], answer[l]);
					cur = l;
				}
				else break;
			}
			else break;
		}

		swap(answer[0], answer[i]);
	}
	return answer;
}