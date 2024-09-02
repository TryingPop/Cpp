/*
날짜 : 2024. 9. 2
이름 : 배성훈
내용 : 덱 2
	문제번호 : 28279번

	자료구조, 덱 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'
#define EMPTY	-1

using namespace std;

int deck[2'000'000];
int len, h = 1'000'000, t = 1'000'000 - 1;

void push_front(int _n)
{

	deck[--h] = _n;
	len++;
}

void push_back(int _n)
{

	deck[++t] = _n;
	len++;
}

int pop_front()
{

	if (len) 
	{
		len--; 
		return deck[h++];
	}
	return EMPTY;
}

int pop_back() 
{

	if (len)
	{

		len--;
		return deck[t--];
	}
	return EMPTY;
}

int size()
{

	return len;
}

int empty()
{

	return len == 0;
}

int front()
{

	if (len) return deck[h];
	return EMPTY;
}

int back()
{

	if (len) return deck[t];
	return EMPTY;
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
			push_front(temp);
		}
		else if (op == 2)
		{

			cin >> temp;
			push_back(temp);
		}
		else if (op == 3)
			cout << pop_front() << endl;
		else if (op == 4)
			cout << pop_back() << endl;
		else if (op == 5)
			cout << size() << endl;
		else if (op == 6)
			cout << empty() << endl;
		else if (op == 7)
			cout << front() << endl;
		else
			cout << back() << endl;
	}
}