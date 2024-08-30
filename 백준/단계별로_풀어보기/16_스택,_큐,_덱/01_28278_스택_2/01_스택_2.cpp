/*
날짜 : 2024. 8. 30
이름 : 배성훈
내용 : 스택 2
	문제번호 : 28278번

	자료구조, 스택 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

int arr[1'000'000];
int len;

inline void Push(int _n) 
{

	arr[len++] = _n;
}

inline int Pop()
{

	if (len)
	{

		len--;
		return arr[len];
	}
	else return -1;
}

inline int Count()
{

	return len;
}

inline bool Empty()
{

	return len == 0;
}

inline int Peek()
{

	if (len) return arr[len - 1];
	else return -1;
}

int main(void)
{

	int n, op, temp;
	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> op;

		if (op == 1)
		{

			cin >> temp;
			Push(temp);
		}
		else if (op == 2) cout << Pop() << endl;
		else if (op == 3) cout << Count() << endl;
		else if (op == 4) cout << Empty() << endl;
		else cout << Peek() << endl;
	}

	return 0;
}