#include <string>
#include <map>

/*
��¥ : 2024. 3. 11
�̸� : �輺��
���� : �𽺺�ȣ 1
	�� ��ȣ�� �̷���� ���ڿ� letter�� �Ű������� �־��� ��,
	letter�� �ؼ��ؼ� ���� �ҹ��ڷ� �ٲ� ���ڿ���
	return �ϵ��� solution �Լ� ����

	�𽺺�ȣ�� �������� ������ �ִ�
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