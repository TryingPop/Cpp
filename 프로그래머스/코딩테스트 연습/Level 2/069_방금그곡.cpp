/*
날짜 : 2024. 8. 13
이름 : 배성훈
내용 : 방금그곡
	방금그곡에서는 TV, 라디오 등에서 나온 음악에 관해 
	제목 등의 정보를 제공하는 서비스이다

	네오는 자신이 기억한 멜로디를 가지고 방금그곡을 이용해 음악을 찾는다
	그런데 라디오 방송에서는 한 음악을 반복해서
	재생할 때도 있어서 네오가 기억하고 있는 멜로디는 음악 끝 부분과
	처음부분이 이어서 재생된 멜로디일 수도 있다

	반대로 한 음악을 중간에 끊을 경우 원본 음악에는 
	네오가 기억한 멜로디가 들어있다해도 그 곡이 네오가 들은
	그 곡이 아닐 수도 있다

	네오는 기억한 멜로디를 재생 시간과 제공된 악보를 직접 보면서
	비교하려고 한다

	방금그곡 서비스에서는 음악 제목,
	재생이 시작되고 끝난 시각, 악보를 제공한다

	네오가 기억한 멜로디와 악보에 사용된 음은
	C, C#, D, D#, E, F, F#, G, G#, A, A# 12개이다

	각 음은 1분에 1개씩 재생된다
	음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는
	음악이 끊김 없이 처음부터 반복해서 재생된다
	음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다

	음악이 00:00를 넘겨서까지 재생되는 일은 없다

	조건이 일치하는 음악이 여러 개일 때에는
	라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다
	재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다

	조건이 일치하는 음악이 없을 때에는 "(None)"을 반환한다

	입력으로 네오가 기억한 멜로디를 담은 문자열 m과
	방송된 곡의 정보를 담고 있는 배열
	musicinfos가 주어진다

	m은 음 1개 이상 1439개 이하로 구성되어 있다
	
	musicinfos는 100개 이하의 곡 정보를 담고 있는 배열로,
	각각의 곡 정보는 음악이 시작한 시각, 끝난 시각, 음악 제목, 악보 정보가
	','로 구분된 문자열이다

	음악의 시작 시각과 끝난 시각은 24시간 HH:MM 형식이다

	음악 제목은 ',' 이외의 출력 가능한 문자로 표현된 
	길이 1 이상 64 이하의 문자열이다

	악보 정보는 음 1개 이상 1439개 이하로 구성되어 있다

	조건과 일치하는 음악 제목을 반환하는 solution 함수 구현


	parameter
	"ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" }


	return
	"WORLD"


	sol
	12:00 에서 12:14까지 방송한 음악은
	C#DEFGABC#DEFGABC 이다
	ABC와 ABC#은 다르므로 ABC는 없다

	그리고 13:00 에서 13:05까지 방송한 음악은
	ABCDE이다
	ABC가 포함되어 있어 WORLD 노래를 반환하면 된다
*/

#include <string>
#include <vector>

using namespace std;

inline void MusicToInt(string& _music)
{

	/*
	
	A, B, C, C#, D, D#, E, F, F#, G, G#을
	숫자로 변환한다
	#이 있으면 + 10
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
	
	HH:MM 형식의 시간을 
	00:00에서 몇 분이 지난 만큼 분단위로 반환
	*/
	int h = (_time[0] - '0') * 10 + (_time[1] - '0');
	int m = (_time[3] - '0') * 10 + (_time[4] - '0');

	return h * 60 + m;
}

inline void ReadStr(const string& _str, string& _name, string& _melody)
{

	/*
	
	str을 조건에 맞게 읽어 name, melody 변수에 담는다
	name : 노래 이름
	melody : 방송된 음
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
	
	문자열 문제
	*/
	string answer = "";
	string name, melody;	// 노래이름, 방송된 음

	int chkLength = 0;		// 재생시간

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