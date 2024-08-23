/*
��¥ : 2024. 8. 23
�̸� : �輺��
���� : ��ǥ��2
	������ȣ : 2587��

	����, ����, ����, ��Ģ���� ������
*/

#include <iostream>
#include <vector>

using namespace std;

bool MyComp(int _f, int _b)
{

	return _f < _b;
}

void HeapSort(vector<int>& _vec)
{

	/*

	�������� ����
	*/
	int len = _vec.size();

	if (len == 1) return;

	for (int i = 1; i < len; i++)
	{

		int cur = i;
		int parent = (cur - 1) >> 1;

		while (cur && MyComp(_vec[parent], _vec[cur]))
		{

			swap(_vec[parent], _vec[cur]);
			cur = parent;
			parent = (cur - 1) >> 1;
		}
	}

	len--;
	swap(_vec[0], _vec[len]);

	while (len > 1)
	{

		int cur = 0;


		while (true)
		{

			int l = cur * 2 + 1;
			int r = cur * 2 + 2;

			if (r < len)
			{

				int next;
				if (MyComp(_vec[l], _vec[r])) next = r;
				else next = l;

				if (MyComp(_vec[cur], _vec[next]))
				{

					swap(_vec[next], _vec[cur]);
					cur = next;
					continue;
				}
			}
			else if (l < len)
			{

				if (MyComp(_vec[cur], _vec[l]))
				{

					swap(_vec[l], _vec[cur]);
					cur = l;
				}
			}

			break;
		}

		len--;
		swap(_vec[0], _vec[len]);
	}
}

int main(void)
{

	vector<int> arr;
	arr.reserve(5);
	int temp, sum = 0;

	for (int i = 0; i < 5; i++) 
	{

		cin >> temp;
		arr.push_back(temp);
		sum += temp;
	}

	HeapSort(arr);

	cout << sum / 5 << '\n' << arr[2];
	return 0;
}