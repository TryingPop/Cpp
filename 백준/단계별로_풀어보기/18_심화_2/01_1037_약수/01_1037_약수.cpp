/*
��¥ : 2024. 9. 4
�̸� : �輺��
���� : ���
	������ȣ : 1037��

	����, ������ ������
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

	int n, temp;
	vector<int> div;
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		div.push_back(temp);
	}

	sort(div.begin(), div.end());

	cout << div[0] * div[div.size() - 1];
	return 0;
}