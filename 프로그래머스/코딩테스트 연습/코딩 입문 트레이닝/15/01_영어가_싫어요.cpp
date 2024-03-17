#include <string>
#include <vector>
#include <map>

/*
날짜 : 2024. 3. 17
이름 : 배성훈
내용 : 영어가 싫어요
	영어로 표기되어 있는 숫자로 바꾸려고 한다
	문자열 numbers가 매개변수로 주어질 때,
	numbers의 정수로 바꿔 return 하도록 solution 함수 구현

	numbers는 소문자로 구성되어 있다
*/

using namespace std;

long long solution(string _numbers)
{

	long long answer = 0;
#if other

	vector<string> numStr =
		{

			"zero", "one", "two",
			"three", "four", "five",
			"six", "seven", "eight", "nine"
		};

	// 찾은 인덱스
	int calc;

	for (int i = 0; i < numStr.size(); i++)
	{

		// numStr의 단어를 모두 찾아 숫자로 바꾼다
		// 해당 문자의 find로 인덱스를 찾고
		while ((calc = _numbers.find(numStr[i])) != string::npos)
		{

			// 해당 문자를 숫자로 변경
			_numbers.replace(calc, numStr[i].size(), to_string(i));
		}
	}

	// long long 형태로 변경
	answer = stoll(numStr);
	return answer;
#endif
	string numStr = "";
	numStr.reserve(50);

	// --------------------
	// 라빈 - 카프 알고리즘
	// 비슷하게 적용
	// 
	// 해당 부분은 replace 메서드를 이용해 해결 가능하다
	// --------------------

	// 3자리씩 끊어 읽을건데, 부족한 단어부분
	// zero 는 4개인데 3개만 읽으니 1개 부족하다는 의미에서 -1이다
	// 마찬가지로 three는 5개인데 3개만 읽으니 2개 부족하다는 의미로 -2이다
	vector<int> rlen = { -1, 0, 0, -2, -1, -1, 0, -2, -2, -1 };

	// 영어 단어를 숫자로 정의해서 해당 숫자와 일치하는지 확인하는게 주된 관건이다
	// 소문자만 주어져 있고 모든 zer, one, two, ... nin은 모두 다르다
	// 충돌 안하는 적당한 자연수를 mod로 잡으면 된다
	// 알파벳 소문자로만 이루어져 있고, 26이상을 잡으면 절대 충돌 안난다
	// 그리고 3자리 밖에 안되어 그냥 초기엔 128을 초과하는 소수 131을 잡고 풀었었다
	// 그런데 2로 잡아도 풀이에 충돌 안일어나서 2로 잡았다
	// 충돌 일어나면 mod 숫자를 바꾸면 된다
	int mod = 2;
	map<int, int> kTon = map<int, int>();
	{

		int sqMod = mod * mod;
		kTon['z' * sqMod + 'e' * mod + 'r'] = 0;
		kTon['o' * sqMod + 'n' * mod + 'e'] = 1;
		kTon['t' * sqMod + 'w' * mod + 'o'] = 2;
		kTon['t' * sqMod + 'h' * mod + 'r'] = 3;
		kTon['f' * sqMod + 'o' * mod + 'u'] = 4;
		kTon['f' * sqMod + 'i' * mod + 'v'] = 5;
		kTon['s' * sqMod + 'i' * mod + 'x'] = 6;
		kTon['s' * sqMod + 'e' * mod + 'v'] = 7;
		kTon['e' * sqMod + 'i' * mod + 'g'] = 8;
		kTon['n' * sqMod + 'i' * mod + 'n'] = 9;
	}

	// 키 값 연산
	int key = 0;
	// 읽은 자리수 연산
	int chk = 0;

	for (const char c : _numbers)
	{

		// 나머지 부분 채우기
		if (chk < 0) chk++;
		else if (chk < 3)
		{

			// 3개 읽는다
			key = key * mod + c;
			chk++;
		}

		if (chk == 3)
		{

			// 키가 완성되었을 때 값 조사
			int val = kTon[key];
			numStr.push_back(val + '0');
			key = 0;
			chk = rlen[val];
		}
	}

	// 이제 numStr을 숫자로 바꾼다
	for (const char c : numStr)
	{

		answer = answer * 10 + c - '0';
	}

	return answer;
}