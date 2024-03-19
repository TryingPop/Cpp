#include <string>
#include <vector>
#include <sstream>

/*
날짜 : 2024. 3. 19
이름 : 배성훈
내용 : OX퀴즈
	덧셈, 뺄셈 수식들이	X [연산자] Y = Z 형태로
	들어있는 문자열 배열 quiz가 매개변수로 주어진다

	수식이 옳다면 O를 틀리다면 X를 순서대로 담은
	배열을 return 하도록 solution 함수를 구현

	연산 기호와 숫자 사이에는 항상 하나의 공백이 존재
	마이너스 기호와 숫자 사이에는 공백이 없다

	수의 범위는 모두 int내에 있다
	X, Y, Z는 각각 0부터 9로 이루어진 숫자며
	맨 앞에 마이너스 기호가 있을 수 있고
	이는 음수를 의미

	X, Y, Z에서 0을 제외하고는 0으로 시작하는 숫자는 없다
	연산자는 +, - 중 하나다
*/

using namespace std;

vector<string> solution(vector<string> _quiz)
{

	vector<string> answer;
	answer.reserve(_quiz.size());

#if other

	stringstream ss;
	for (const string str : _quiz)
	{

		int f, b, a;
		char op;
		char equal;

		bool isWrong;
		// stringstream ss;
		ss.clear();
		ss.str(str);

		ss >> f >> op >> b >> equal >> a;


		if (op == '+') isWrong = f + b != a;
		else isWrong = f - b != a;

		if (isWrong) answer.push_back("X");
		else answer.push_back("O");
	}
#endif

	for (const string eval : _quiz)
	{

		// 입력 받은 여부
		bool isF = false;		// 첫 번째 숫자 입력 받았는지?
		bool isO = false;		// 연산자 입력 받았는지?
		bool isB = false;		// 두 번째 숫자 입력 받았는지?
		bool isE = false;		// 이꼴 입력 받았는지?

		// 숫자 
		int f = 0;				// 맨앞
		int b = 0;				// 중간
		int a = 0;				// 정답

		// +, -
		bool opPlus = true;		// 연산자가 +?
		bool nPlus = true;		// 숫자가 양수

		for (const char c : eval)
		{

			if (c == ' ')
			{

				if (!isF)
				{

					isF = true;
					f = nPlus ? f : -f;
					nPlus = true;
				}
				else if (!isO) isO = true;
				else if (!isB)
				{

					isB = true;
					b = nPlus ? b : -b;
					nPlus = true;
				}
				else if (!isE) isE = true;
			}
			// + 연산 확인
			else if (isF && !isO) opPlus = c == '+';
			// = 무시
			else if (isB && !isE) continue;
			else 
			{

				// 숫자 입력 받는 경우
				if (c == '-') nPlus = false;
				else if (!isF) f = f * 10 + c - '0';
				else if (!isB) b = b * 10 + c - '0';
				else a = a * 10 + c - '0';
			}
		}

		a = nPlus ? a : -a;

		// 연산 결과 확인
		if (opPlus)
		{

			if (f + b == a) answer.push_back("O");
			else answer.push_back("X");
		}
		else 
		{

			if (f - b == a) answer.push_back("O");
			else answer.push_back("X");
		}
	}

	return answer;
}