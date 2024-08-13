/*
��¥ : 2024. 8. 13
�̸� : �輺��
���� : ��ݱװ�
	��ݱװ���� TV, ���� ��� ���� ���ǿ� ���� 
	���� ���� ������ �����ϴ� �����̴�

	�׿��� �ڽ��� ����� ��ε� ������ ��ݱװ��� �̿��� ������ ã�´�
	�׷��� ���� ��ۿ����� �� ������ �ݺ��ؼ�
	����� ���� �־ �׿��� ����ϰ� �ִ� ��ε�� ���� �� �κа�
	ó���κ��� �̾ ����� ��ε��� ���� �ִ�

	�ݴ�� �� ������ �߰��� ���� ��� ���� ���ǿ��� 
	�׿��� ����� ��ε� ����ִ��ص� �� ���� �׿��� ����
	�� ���� �ƴ� ���� �ִ�

	�׿��� ����� ��ε� ��� �ð��� ������ �Ǻ��� ���� ���鼭
	���Ϸ��� �Ѵ�

	��ݱװ� ���񽺿����� ���� ����,
	����� ���۵ǰ� ���� �ð�, �Ǻ��� �����Ѵ�

	�׿��� ����� ��ε�� �Ǻ��� ���� ����
	C, C#, D, D#, E, F, F#, G, G#, A, A# 12���̴�

	�� ���� 1�п� 1���� ����ȴ�
	������ �ݵ�� ó������ ����Ǹ� ���� ���̺��� ����� �ð��� �� ����
	������ ���� ���� ó������ �ݺ��ؼ� ����ȴ�
	���� ���̺��� ����� �ð��� ª�� ���� ó������ ��� �ð���ŭ�� ����ȴ�

	������ 00:00�� �Ѱܼ����� ����Ǵ� ���� ����

	������ ��ġ�ϴ� ������ ���� ���� ������
	�������� ����� �ð��� ���� �� ���� ������ ��ȯ�Ѵ�
	����� �ð��� ���� ��� ���� �Էµ� ���� ������ ��ȯ�Ѵ�

	������ ��ġ�ϴ� ������ ���� ������ "(None)"�� ��ȯ�Ѵ�

	�Է����� �׿��� ����� ��ε� ���� ���ڿ� m��
	��۵� ���� ������ ��� �ִ� �迭
	musicinfos�� �־�����

	m�� �� 1�� �̻� 1439�� ���Ϸ� �����Ǿ� �ִ�
	
	musicinfos�� 100�� ������ �� ������ ��� �ִ� �迭��,
	������ �� ������ ������ ������ �ð�, ���� �ð�, ���� ����, �Ǻ� ������
	','�� ���е� ���ڿ��̴�

	������ ���� �ð��� ���� �ð��� 24�ð� HH:MM �����̴�

	���� ������ ',' �̿��� ��� ������ ���ڷ� ǥ���� 
	���� 1 �̻� 64 ������ ���ڿ��̴�

	�Ǻ� ������ �� 1�� �̻� 1439�� ���Ϸ� �����Ǿ� �ִ�

	���ǰ� ��ġ�ϴ� ���� ������ ��ȯ�ϴ� solution �Լ� ����


	parameter
	"ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" }


	return
	"WORLD"


	sol
	12:00 ���� 12:14���� ����� ������
	C#DEFGABC#DEFGABC �̴�
	ABC�� ABC#�� �ٸ��Ƿ� ABC�� ����

	�׸��� 13:00 ���� 13:05���� ����� ������
	ABCDE�̴�
	ABC�� ���ԵǾ� �־� WORLD �뷡�� ��ȯ�ϸ� �ȴ�
*/

#include <string>
#include <vector>

using namespace std;

inline void MusicToInt(string& _music)
{

	/*
	
	A, B, C, C#, D, D#, E, F, F#, G, G#��
	���ڷ� ��ȯ�Ѵ�
	#�� ������ + 10
	*/

	int idx = 0;
	for (int i = 0; i < _music.length(); i++)
	{

		if (_music[i] == '#') _music[idx - 1] += 100;
		else _music[idx++] = _music[i] - 'A';
	}

	_music.resize(idx);
}

inline int TimeToInt(string& _time)
{

	/*
	
	HH:MM ������ �ð��� 
	00:00���� �� ���� ���� ��ŭ �д����� ��ȯ
	*/
	int h = (_time[0] - '0') * 10 + (_time[1] - '0');
	int m = (_time[3] - '0') * 10 + (_time[4] - '0');

	return h * 60 + m;
}

inline void ReadStr(const string& _str, string& _name, string& _melody)
{

	/*
	
	str�� ���ǿ� �°� �о� name, melody ������ ��´�
	name : �뷡 �̸�
	melody : ��۵� ��
	*/
	string temp = _str.substr(0, 5);
	int s = TimeToInt(temp);
	temp = _str.substr(6, 5);
	int e = TimeToInt(temp);

	_name.clear();
	int idx = 12;
	while (_str[idx] != ',')
	{

		_name.push_back(_str[idx++]);
	}

	_melody.clear();
	idx++;
	temp = _str.substr(idx);
	MusicToInt(temp);

	int time = e - s;
	idx = 0;
	while (time--) 
	{

		_melody.push_back(temp[idx++]);
		if (idx == temp.length()) idx = 0;
	}
}

string solution(string _m, vector<string> _musicinfos)
{

	/*
	
	���ڿ� ����
	*/
	string answer = "";
	string name, melody;	// �뷡�̸�, ��۵� ��

	int chkLength = 0;		// ����ð�

	MusicToInt(_m);

	for (const string& str : _musicinfos)
	{

		ReadStr(str, name, melody);
		if (melody.length() <= chkLength
			|| melody.find(_m) == string::npos) continue;

		chkLength = melody.length();
		answer = name;
	}

	if (answer == "") answer = "(None)";
	return answer;
}