/*
��¥ : 2024. 7. 22
�̸� : �輺��
���� : ���ϸ� ����
	�ܼ��� ���� �ڵ� ���� �ƴ� ���ϸ� ���Ե� ���ڸ� �ݿ���
	���� ����� ����� ���� ���α׷��� �����Ѵ�

	�ҽ� ���� ����ҿ� ����� ���ϸ��� 100���� �̳���,
	���� ��ҹ���, ����, ����, ��ħǥ, ���� ��ȣ������ �̷���� �ִ�
	���ϸ��� �����ڷ� �����ϸ�, ���ڸ� �ϳ� �̻� �����ϰ� �ִ�

	���ϸ��� ũ�� HEAD, NUMBER, TAIL�� �� �κ����� �����ȴ�
	HEAD�� ���ڰ� �ƴ� ���ڷ� �̷���� ������, �ּ� �� ���� �̻��̴�

	NUMBER�� �� ���ڿ��� �ִ� �ټ� ���� ������ ���ӵ� ���ڷ� �̷���� ������,
	���ʿ� 0�� �� �� �ִ� 0���� 99'999 ������ ���ڷ�, 00000�̳�
	0101 � �����ϴ�

	TAIL�� �� ������ �κ����� ���⿡�� ���ڰ� �ٽ� ��Ÿ�� ���� ������,
	�ƹ� ���ڵ� ���� �� �ִ�

	���ϸ��� �� �κ����� ���� ��, ���� ���ؿ� ���� ���ϸ��� �����Ѵ�
	���ϸ��� �켱 HEAD �κ��� �������� ���� ������ �����Ѵ�
	�̶�, ���ڿ� �� �� ��ҹ��� ������ ���� �ʴ´�

	���ϸ� HEAD �κ��� ��ҹ��� ���̿ܿ��� ���� ���,
	NUMBER�� ���� ������ �����Ѵ�
	���� ���� 0 �� ���õǸ�, 012�� 12�� ���� �ÿ� ���� ������ ó���ȴ�

	�� ������ HEAD �κа�, NUMBER�� ���ڵ� ���� ���,
	���� �Է¿� �־��� ������ �����Ѵ�
	���� �Ŀ��� �Է� �� �־��� �� ������ ������ �ٲ��� �ȵȴ�

	�̷��� ��Ģ�� �� ���ϸ� ���� ���α׷��� ��������

	�Է����� ���ڿ� �迭 files�� �־�����
	files�� 1000�� ������ ���ϸ��� �����ϴ� ���ڿ� �迭�̴�
	�� ���ϸ��� 100���� ���� ���̷�,
	���� ��ҹ���, ����, ����, ��ħǥ, �����ȣ������ �̷���� �ִ�
	���ϸ��� �����ڷ� �����ϸ�, ���ڸ� �ϳ� �̻� �����ϰ� �ִ�

	�ߺ��� ���ϸ��� ������, ��ҹ��ڳ� ���� �� �κ��� 0 ���̰� �ִ� ����
	�԰� �־��� �� �ִ�

	parameter
	{ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" }


	return
	{ "img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png" }


	sol
	���ϸ��� HEAD �κ��� ��� �ҹ��ڷ� ǥ���ϸ� img�� �����ϴ�
	��ҹ��� ���� �̿ܿ� ��� �����Ƿ�
	
	
	�׷��� NUMBERS�� �������� ���ĵǾ�� �Ѵ�
	1, 2, 10, 12 ������ ���ĵǾ�� �Ѵ�
	�׸��� 1������ ���� ������ �����ؾߵȴ�
	�׷��� img1.png, IMG01.GIF ������
	2�� ���������� ���� ������ ����ؾ��Ѵ�
	�̷��� �����ϸ�
	"img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"
	�� �ȴ�


	ó������ ��ҹ��� ���� �κп��� ���̱��� ���� '-', ' ', '.'�� ���� ������ �˾Ҵ�;
*/

#include <vector>
#include <string>
#include <algorithm>

#define pi pair<int, int>
#define psii pair<string, pi>

#define mp make_pair

#define f(X) X.first
#define sf(X) X.second.first
#define ss(X) X.second.second

using namespace std;

inline void Upper(string& _str) 
{

	/*
	
	�ҹ��ڸ� �빮�ڷ�
	*/
	for (int i = 0; i < _str.length(); i++)
	{

		if ('a' <= _str[i] && _str[i] <= 'z') _str[i] = _str[i] - 'a' + 'A';
	}
}

inline void Divide(const string& _str, psii& _ret)
{

	/*
	
	HEAD, NUMBER�� ��ȯ
	HEAD�� ���� �� ���ڸ� ��´�
	NUMBER�� ���� ���� ���� ���� �� ���ڸ� ��´�
	������ �����Ѵ�
	*/

	bool flag = true;
	for (const char c : _str)
	{

		if ('0' <= c && c <= '9')
		{

			if (flag) flag = false;
			sf(_ret) = sf(_ret) * 10 + c - '0';
		}
		else if (flag) f(_ret).push_back(c);
		// ����
		else return;
	}
}

inline bool MyComp(psii& _f, psii& _b)
{

	if (f(_f) != f(_b)) return f(_f) < f(_b);

	else if (sf(_f) != sf(_b)) return sf(_f) < sf(_b);
	else return ss(_f) < ss(_b);
}

vector<string> solution(vector<string> _files)
{

	vector<string> answer;
	answer.reserve(_files.size());

	// ���� ���ڿ��� �������� ���ο� �ڷᱸ���� ��´�
	// HEAD, NUMBER, files������ idx
	vector<psii> vec(_files.size(), mp("", mp(0, 0)));
	string temp;

	// ���ο� �ڷᱸ���� ���� �Է�
	for (int i = 0; i < _files.size(); i++)
	{

		temp = _files[i];
		Upper(temp);
		Divide(temp, vec[i]);
		ss(vec[i]) = i;
	}

	sort(vec.begin(), vec.end(), MyComp);

	// ���ĵ� ���ο� �ڷᱸ���� ��� ���ǿ� ���� ����
	for (int i = 0; i < vec.size(); i++)
	{

		answer.push_back(_files[ss(vec[i])]);
	}

	return answer;
}