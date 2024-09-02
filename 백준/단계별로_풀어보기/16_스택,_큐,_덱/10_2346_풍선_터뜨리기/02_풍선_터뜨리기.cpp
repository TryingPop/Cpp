/*
��¥ : 2024. 9. 2
�̸� : �輺��
���� : ǳ�� �Ͷ߸���
	������ȣ : 2346��

	�ڷᱸ��, �� ������
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
using namespace std;

int main(void)
{

	int n, temp, cur, r, move;
	vector<int> card;
	vector<bool> use;

	FAST_IO;

	cin >> n;
	use.resize(n, false);

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		card.push_back(temp);
	}

	cur = 0;
	r = n;
	while (true)
	{

		cout << cur + 1 << EMPTY;
		use[cur] = true;
		r--;

		if (r)
		{

			move = card[cur];
			while (move != 0)
			{

				if (move > 0)
				{

					cur++;
					if (cur == n) cur = 0;
					if (use[cur]) continue;
					move--;
				}
				else
				{

					cur--;
					if (cur == -1) cur = n - 1;
					if (use[cur]) continue;
					move++;
				}
			}
		}
		else break;
	}

	return 0;
}