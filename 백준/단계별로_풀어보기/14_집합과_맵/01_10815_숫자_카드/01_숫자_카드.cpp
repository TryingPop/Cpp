/*
��¥ : 2024. 8. 26
�̸� : �輺��
���� : ���� ī��
	������ȣ : 10815��
*/

#include <iostream>
#include <unordered_set>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
using namespace std;

int main(void)
{

	unordered_set<int> myCard;
	int n, temp;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		myCard.insert(temp);
	}

	cin >> n;
	for (int i = 0; i < n; i++) 
	{

		cin >> temp;
		cout << myCard.count(temp) << EMPTY;
	}

	return 0;
}