/*
날짜 : 2024. 9. 1
이름 : 배성훈
내용 : 큐 2
	문제번호 : 18258번

	자료구조, 큐 문제다
*/

#include <iostream>
#include <vector>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

int q[2'000'000];
int h, t = -1, len;

inline void push(int _n)
{

	q[++t] = _n;
	len++;
}

inline int pop()
{

	if (len == 0) return -1;
	len--;
	return q[h++];
}

inline int size()
{

	return len;
}

inline bool empty() 
{

	return len == 0;
}

inline int front() 
{

	if (len) return q[h];
	else return -1;
}

inline int back()
{

	if (len) return q[t];
	else return -1;
}

int main(void)
{

	string PUSH = "push";
	string POP = "pop";
	string SIZE = "size";
	string EMPTY = "empty";
	string FRONT = "front";
	string BACK = "back";

	int n, temp;
	string op;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> op;
	
		if (op == PUSH)
		{

			cin >> temp;
			push(temp);
		}
		else if (op == POP)
			cout << pop() << endl;
		else if (op == SIZE)
			cout << size() << endl;
		else if (op == EMPTY)
			cout << empty() << endl;
		else if (op == FRONT)
			cout << front() << endl;
		else if (op == BACK)
			cout << back() << endl;
	}
	return 0;
}