/*
날짜 : 2024. 7. 22
이름 : 배성훈
내용 : 파일명 정렬
	단순한 문자 코드 순이 아닌 파일명에 포함된 숫자를 반영한
	정렬 기능을 저장소 관리 프로그램에 구현한다

	소스 파일 저장소에 저장된 파일명은 100글자 이내로,
	영문 대소문자, 숫자, 공백, 마침표, 빼기 부호만으로 이루어져 있다
	파일명은 영문자로 시작하며, 숫자를 하나 이상 포함하고 있다

	파일명은 크게 HEAD, NUMBER, TAIL의 세 부분으로 구성된다
	HEAD는 숫자가 아닌 문자로 이루어져 있으며, 최소 한 글자 이상이다

	NUMBER는 한 글자에서 최대 다섯 글자 사이의 연속된 숫자로 이루어져 있으며,
	앞쪽에 0이 올 수 있다 0부터 99'999 사이의 숫자로, 00000이나
	0101 등도 가능하다

	TAIL은 그 나머지 부분으로 여기에는 숫자가 다시 나타날 수도 있으며,
	아무 글자도 없을 수 있다

	파일명을 세 부분으로 나눈 후, 다음 기준에 따라 파일명을 정렬한다
	파일명은 우선 HEAD 부분을 기준으로 사전 순으로 정렬한다
	이때, 문자열 비교 시 대소문자 구분을 하지 않는다

	파일명 HEAD 부분이 대소문자 차이외에는 같을 경우,
	NUMBER의 숫자 순으로 정렬한다
	숫자 앞의 0 은 무시되며, 012와 12는 정렬 시에 같은 값으로 처리된다

	두 파일의 HEAD 부분과, NUMBER의 숫자도 같을 경우,
	원래 입력에 주어진 순서를 유지한다
	정렬 후에도 입력 시 주어진 두 파일의 순서가 바뀌어서는 안된다

	이러한 규칙일 때 파일명 정렬 프로그램을 구현하자

	입력으로 문자열 배열 files가 주어진다
	files는 1000개 이하의 파일명을 포함하는 문자열 배열이다
	각 파일명은 100글자 이하 길이로,
	영문 대소문자, 숫자, 공백, 마침표, 빼기부호만으로 이루어져 있다
	파일명은 영문자로 시작하며, 숫자를 하나 이상 포함하고 있다

	중복된 파일명은 없으나, 대소문자나 숫자 앞 부분의 0 차이가 있는 경우는
	함게 주어질 수 있다

	parameter
	{ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" }


	return
	{ "img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png" }


	sol
	파일명의 HEAD 부분은 모두 소문자로 표현하면 img로 동일하다
	대소문자 차이 이외에 모두 같으므로
	
	
	그러면 NUMBERS를 기준으로 정렬되어야 한다
	1, 2, 10, 12 순으로 정렬되어야 한다
	그리고 1끼리는 기존 순서를 유지해야된다
	그래서 img1.png, IMG01.GIF 순서다
	2도 마찬가지로 기존 순서로 출력해야한다
	이렇게 나열하면
	"img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"
	이 된다


	처음에는 대소문자 차이 부분에서 차이까지 끊고 '-', ' ', '.'는 같게 보는줄 알았다;
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
	
	소문자를 대문자로
	*/
	for (int i = 0; i < _str.length(); i++)
	{

		if ('a' <= _str[i] && _str[i] <= 'z') _str[i] = _str[i] - 'a' + 'A';
	}
}

inline void Divide(const string& _str, psii& _ret)
{

	/*
	
	HEAD, NUMBER를 반환
	HEAD에 숫자 앞 문자만 담는다
	NUMBER는 가장 먼저 나온 가장 긴 숫자를 담는다
	꼬리는 무시한다
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
		// 꼬리
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

	// 기존 문자열을 변형시켜 새로운 자료구조에 담는다
	// HEAD, NUMBER, files에서의 idx
	vector<psii> vec(_files.size(), mp("", mp(0, 0)));
	string temp;

	// 새로운 자료구조에 정보 입력
	for (int i = 0; i < _files.size(); i++)
	{

		temp = _files[i];
		Upper(temp);
		Divide(temp, vec[i]);
		ss(vec[i]) = i;
	}

	sort(vec.begin(), vec.end(), MyComp);

	// 정렬된 새로운 자료구조를 출력 조건에 맞춰 변형
	for (int i = 0; i < vec.size(); i++)
	{

		answer.push_back(_files[ss(vec[i])]);
	}

	return answer;
}