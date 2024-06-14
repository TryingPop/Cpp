/*
날짜 : 2024. 6. 14
이름 : 배성훈
내용 : 다음 큰 숫자
	자연수 n이 주어졌을 때,
	n의 다음 큰 숫자는 다음과 같이 정의한다
	조건 1. n의 다음 큰 숫자는 n보다 큰 자연수
	조건 2. n의 다음큰 숫자와 n은 이진수로 변환했을 때
		1의 갯수가 같다
	조건 3. n의 다음 큰 숫자는 앞의 조건을 만족하는 숫자 중
		가장 작은수이다

	자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를
	return 하는 solution 함수를 구현

	parameter
	78

	return
	83
*/

#include <string>
#include <vector>

using namespace std;

void NextBinaryNum(vector<int>& _binaryNum)
{

    // 조건에 맞는 이진수를 역순으로 찾아준다
    int find = 0;           // 1의 개수
    bool chk2 = true;       // 0을 발견해서 탈출
    bool chk1 = false;      // 처음 0들이 아닌지 확인

    for (int i = 0; i < _binaryNum.size(); i++)
    {

        if (chk1 && _binaryNum[i] == 0)
        {

            _binaryNum[i] = 1;
            chk2 = false;
            find--;
            break;
        }

        if (_binaryNum[i] == 1)
        {

            chk1 = true;
            find++;
        }

        _binaryNum[i] = 0;
    }

    if (chk2)
    {

        _binaryNum.push_back(1);
        find--;
    }

    for (int i = 0; i < _binaryNum.size(); i++)
    {

        if (!find) break;
        find--;
        _binaryNum[i] = 1;
    }
}

int solution(int _n) {
    int answer = 0;

    // 이진수 (역순으로 저장)
    vector<int> bn;
    bn.reserve(20);

    while (_n)
    {

        if (_n & 1) bn.push_back(1);
        else bn.push_back(0);

        _n >>= 1;
    }

    // 다음 수 찾기 Greedy
    NextBinaryNum(bn);

    // 역순으로 저장된 이진수를 십진수로 변환
    for (int i = 0; i < bn.size(); i++)
    {

        if (bn[i]) answer |= 1 << i;
    }
    return answer;
}