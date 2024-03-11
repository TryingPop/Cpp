#include <string>
#include <map>

/*
날짜 : 2024. 3. 11
이름 : 배성훈
내용 : 모스부호 1
	모스 부호로 이루어진 문자열 letter가 매개변수로 주어질 때,
	letter를 해석해서 영어 소문자로 바꾼 문자열을
	return 하도록 solution 함수 구현

	모스부호는 공백으로 나눠져 있다
*/

using namespace std;

string solution(string _letter)
{

	string answer;
    
    map <string, char> morse =
    {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'},
        {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},{"-.-", 'k'}, {".-..", 'l'},
        {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'},
        {"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'},
        {"-.--", 'y'}, {"--..", 'z'}
    };

    string temp;
    temp.reserve(4);

    for (const char c : _letter)
    {

        if (c == ' ')
        {

            answer.push_back(morse[temp]);
            temp.clear();
        }
        else temp.push_back(c);
    }

    answer.push_back(morse[temp]);
    return answer;
}