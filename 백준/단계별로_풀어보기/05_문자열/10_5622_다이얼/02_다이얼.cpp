/*
��¥ : 2024. 8. 8
�̸� : �輺��
���� : ���̾�
	������ȣ : 5622��

	���� ������
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{

	string str;
	int ret = 0;
	vector<char> cTn(128, -1);

	cTn['A'] = 3;
	cTn['B'] = 3;
	cTn['C'] = 3;

	cTn['D'] = 4;
	cTn['E'] = 4;
	cTn['F'] = 4;

	cTn['G'] = 5;
	cTn['H'] = 5;
	cTn['I'] = 5;

	cTn['J'] = 6;
	cTn['K'] = 6;
	cTn['L'] = 6;

	cTn['M'] = 7;
	cTn['N'] = 7;
	cTn['O'] = 7;
	
	cTn['P'] = 8;
	cTn['Q'] = 8;
	cTn['R'] = 8;
	cTn['S'] = 8;

	cTn['T'] = 9;
	cTn['U'] = 9;
	cTn['V'] = 9;

	cTn['W'] = 10;
	cTn['X'] = 10;
	cTn['Y'] = 10;
	cTn['Z'] = 10;

	cin >> str;

	for (char c : str)
	{

		ret += cTn[c];
	}

	cout << ret;
	return 0;
}