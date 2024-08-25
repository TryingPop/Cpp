/*
날짜 : 2024. 8. 25
이름 : 배성훈
내용 : 나이순 정렬
	문제번호 : 10814번

	정렬 문제다
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
#define endl	'\n'
using namespace std;

struct User
{

	int key;
	int age;
	string name;

	User(int _key, int _age, string& _name)
		: key(_key), age(_age), name(_name) { }
};

bool MyComp(User& _f, User& _b)
{

	if (_f.age != _b.age) return _f.age < _b.age;
	return _f.key < _b.key;
}

void HeapSort(vector<User>& _arr)
{

	int len = _arr.size();
	for (int i = 1; i < len; i++)
	{

		int cur = i;

		while (cur)
		{

			int parent = (cur - 1) >> 1;
			if (MyComp(_arr[parent], _arr[cur]))
			{

				swap(_arr[cur], _arr[parent]);
				cur = parent;
			}
			else break;
		}
	}

	while (len > 1)
	{

		len--;
		swap(_arr[0], _arr[len]);
		
		int cur = 0;
		while (cur < len)
		{

			int l = cur * 2 + 1;
			int r = cur * 2 + 2;

			if (r < len)
			{

				int next = MyComp(_arr[l], _arr[r]) ? r : l;
				if (MyComp(_arr[cur], _arr[next])) 
				{

					swap(_arr[cur], _arr[next]);
					cur = next;
					continue;
				}
			}
			else if (l < len)
			{

				if (MyComp(_arr[cur], _arr[l])) swap(_arr[cur], _arr[l]);
			}

			break;
		}
	}
}

int main(void)
{

	int n, age, key = 1;
	string name;
	vector<User> users;

	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> age >> name;

		users.push_back(User(key++, age, name));
	}

	HeapSort(users);

	for (int i = 0; i < n; i++)
	{

		cout << users[i].age << EMPTY << users[i].name << endl;
	}
	return 0;
}