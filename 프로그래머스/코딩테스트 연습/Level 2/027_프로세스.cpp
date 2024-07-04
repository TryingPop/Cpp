/*
날짜 : 2024. 7. 4
이름 : 배성훈
내용 : 프로세스
    운영체제의 역할 중 하나는 컴퓨터 시스템의 자원을 효율적으로 관리하는 것이다
    여기서는 운영체제가 다음 규칙에 따라 프로세스를 관리한다고 하자
        1. 실행 대기 큐에서 대기 중인 프로세스를 하나 꺼낸다
        2. 큐에 대기 중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면
            방금 꺼낸 프로세스를 다시 큐에 넣는다
        3. 만약 그러한 프로세스가 없다면 방금 꺼낸 프로세스를 실행한다
            3. 1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료한다

    현재 실행대기 큐(Queue)에 있는 프로세스의 중요도 순서가 순서대로 담긴 배열
    priorities와 몇 번째로 실행되는지 알고 싶은 프로세스의 위치를 알려주는
    location이 매개변수로 주어질 때, 해당 프로세스가 몇 번째로 실행되는지 
    return 하는 solution 함수 구현

    priorities의 길이는 1 이상 100 이하
    priorities의 원소는 1 이상 9 이하인 정수
    priorities의 원소는 우선순위를 나타내며 값이 클수록 우선순위가 높다
    location은 0이상 대기 큐에 있는 프로세스 수 - 1 이하의 값을 갖는다
        그리고 가장 앞에 있는걸 0, 두 번째는 1, ... 으로 표현된다
    
    prameter
    { 2, 1, 3, 2 }, 0


    return
    3

    
    sol
    대기 중인 프로세스를 
    { A, B, C, D }라하면 A가 몇 번째에 실행되는지 찾아야한다

    그러면 A는 우선순위가 2이고 우선순위 3으로 더 높은 프로세스 C가 존재해
    다시 큐에 들어간다
    { B, C, D, A }

    B역시 마찬가지로 다시 큐에 들어간다
    { C, D, A, B }

    C보다 높은 우선순위는 없으므로 C가 실행된다
    { D, A, B }

    D보다 높은 우선순위는 없으므로 D가 실행된다
    { A, B }

    A보다 높은 우선순위는 없으므로 A가 실행된다
    그래서 A는 3번째에 실행된다
*/
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> _priorities, int _location) 
{

    int answer = 0;

    // 브루트 포스
    // O(N^2)
    queue<pair<int, int>> q;        // 우선순위, 초기 위치
    vector<int> cnt(10, 0);         // 우선순위 개수
    int idx = 0;
    for (const int p : _priorities)
    {

        // 우선순위 개수 확인
        cnt[p]++;
        // 순차적으로 큐에 넣는다
        q.push(make_pair(p, idx++));
    }

    // 가장 높은 우선순위를 찾는다
    for (int i = 9; i > 0; i--)
    {

        if (cnt[i])
        {

            idx = i;
            break;
        }
    }

    while (q.size())
    {

        pair<int, int> node = q.front();
        q.pop();
        if (node.first != idx)
        {

            // 우선순위 높은게 남아있어 넘어간다
            q.push(node);
            continue;
        }

        // 우선순위 가장 높은거
        ++answer;
        if (node.second == _location) break;
        // 현재 우선순위 다 사용되서 최우선 순위 갱신
        cnt[idx]--;
        if (cnt[idx]) continue;
        idx--;

        while (cnt[idx] == 0)
        {

            idx--;
        }
    }

    return answer;
}