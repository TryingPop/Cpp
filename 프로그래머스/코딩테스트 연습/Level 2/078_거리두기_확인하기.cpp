/*
날짜 : 2024. 8. 22
이름 : 배성훈
내용 : 거리두기 확인하기
    코로나 바이러스 감염 예방을 위해 응시자들은 거리를 둬서 대기를 해야한다
    아래 규칙으로 대기실에 거리를 두고 앉도록 안내를 하고 있다

    1. 대기실은 5개이며, 각 대기실은 5 x 5 크기이다
    2. 거리두기를 위하여 응시자들 끼리는 맨해튼 거리가 2 이하로 앉으면 안된다
    3. 응시자가 앉아있는 자리 사이가 파티션으로 막혀 있을 경우에는 허용

    5개의 대기실을 봤을 때
    거리두기를 잘 지키고 있는지 확인하고 싶다

    응시자들의 정보와 대기실 구조를 대기실별로 담은 
    2차원 문자열 배열 places가 매개변수로 주어질 때,
    각 대기실별로 거리두기를 지키고 있으면 1을,
    한 명이라도 지키지 않고 있으면 0을 배열에 담아 
    return 하는 solution 함수 구현

    places의 행의 길이는 5,
    places의 열의 길이도 5,
    places의 원소는 P, O, X 로 이루어진 문자열

    places원소의 길이도 5이다
    P는 응시자가 앉아있는 자리를 의미하고,
    O는 빈테이블을 의미하고,
    X는 파티션을 의미한다

    입력으로 주어지는 5개의 대기실의 크기는 모두 5 x 5이다

    return 값 형식은
    1차원 정수 배열에 5개의 원소를 담아 return

    places에 담겨 있는 5개의 대기실의 순서대로 거리두기 준수 여부를 
    차례대로 배열에 담는다

    각 대기실 별로 모든 응시자가 거리두기를 지키고 있으면 1을
    한명이라도 지키지 않고 있으면 0을 담는다


    parameter
    {   { "POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP" }, 
        { "POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" }, 
        { "PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX" }, 
        { "OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" }, 
        { "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" } }

    
    return
    { 1, 0, 1, 1, 1 }


    sol
    2번째의 경우 맵을 보면
        P   O   O   P   X
        O   X   P   X   P
        P   X   X   X   O
        O   X   X   X   O
        O   O   O   P   P
    0, 0과 2, 0의 사람이 거리두기를 지키지 않고 있다
    이외에도 1, 2와 0, 3 사람 그리고
    4, 3과 4, 4 응시자도 거리두기를 지키지 않고 있다
*/

#include <string>
#include <vector>

using namespace std;

inline bool ChkInvalidPos(int _r, int _c)
{

    /*

    유효한 좌표인지 확인
    */
    return _r < 0 || _c < 0 || _r >= 5 || _c >= 5;
}

inline bool Find(vector<string>& _board)
{

    /*

    1칸 이동한 곳에 값을 누적시킨다
    만약 2개 이상 누적되면 거리 2 이하이므로 거리두기를 지키지 못한다
    */

    vector<vector<int>> chk(5, vector<int>(5, 0));
    vector<int> dirR = { 0, -1, 0, 1, 0 };
    vector<int> dirC = { 0, 0, -1, 0, 1 };

    for (int r = 0; r < 5; r++)
    {

        for (int c = 0; c < 5; c++)
        {

            // P가 아니면 탐색 X
            if (_board[r][c] != 'P') continue;

            for (int i = 0; i < 5; i++)
            {

                int nextR = r + dirR[i];
                int nextC = c + dirC[i];

                if (ChkInvalidPos(nextR, nextC)
                    || _board[nextR][nextC] == 'X') continue;

                chk[nextR][nextC]++;
                if (chk[nextR][nextC] == 2) return false;
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{

    /*

    애드혹
    */
    vector<int> answer;

    for (vector<string>& board : places)
    {

        if (Find(board)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}