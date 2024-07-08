/*
날짜 : 2024. 7. 9
이름 : 배성훈
내용 : 캐시
    캐시 크기(cacheSize)와 도시이름 배열(cities)를 입력 받는다
    cacheSize는 0이상 30이하의 정수이며,
    cities는 도시이름으로 최대 도시 수는 10만개 이다
    각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되어 있으며
    대소문자 구분을 하지 않는다
    도시 이름은 최대 20자로 이루어져 있다

    도시 이름 배열을 순서대로 처리할 때 총 실행시간을 구해야한다
    캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다
    cache hit일 경우 실행시간은 1이다
    cache miss일 경우 실행시간은 5이다


    parameter
    3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "NewYork" }


    return
    26


    sol
    캐시에 저장된 데이터는 없어 Jeju를 추가해야한다
    그래서 cache miss로 실행시간 5이다
    캐시 : Jeju

    캐시에 Pangyo는 저장되어 있지 않으므로 추가해야한다
    그래서 cache miss로 실행시간은 5이다
    캐시 : Pangyo, Jeju

    캐시에 Seoul은 저장되어져 있지 않으므로 Seoul을 추가해야 한다
    그래서 cache miss로 실행시간은 5이다
    캐시 : Seoul, Pangyo, Jeju

    캐시에 Jeju가 저장되어져 있다
    그래서 cache hit로 실행시간은 1이다
    캐시 : Jeju, Seoul, Pangyo

    ...

    이렇게 진행하다가
    NewYork에 가면
    캐시 : Seoul, Pangyo, Jeju
    이므로 현재 캐시는 가득 차 있고, NewYork는 캐시에 있지 않다
    가장 마지막에 사용한 Jeju를 빼고 NewYork를 넣는다
    그래서 cache miss로 실행시간은 5이다
    캐시 : NewYork, Seoul, Pangyo

    이렇게 구하면
    { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "NewYork" }
    { 5,        5,      5,          1,      1,      1,      1,      1,          1,      5 }
    의 시간이 걸리고 전체 26의 시간이 된다
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{

private:
    bool use;
    Node* prev;
    Node* next;

public:
    Node() : use(false), prev(NULL), next(NULL) { }

    void Connect(Node* _head)
    {

        // 노드 잇기
        // 널 체크 해야하나 안했다
        if (use) DisConnect();

        Node* n = _head->next;
        n->prev = this;
        _head->next = this;

        this->prev = _head;
        this->next = n;
        use = true;
    }

    void DisConnect()
    {

        // 노드 끊기
        Node* n = this->next;
        Node* p = this->prev;

        n->prev = p;
        p->next = n;

        this->use = false;
    }

    void SetPrev(Node* _prev)
    {

        prev = _prev;
    }

    void SetNext(Node* _next)
    {

        next = _next;
    }

    Node* GetPrev()
    {

        return this->prev;
    }

    Node* GetNext()
    {

        return this->next;
    }

    bool Use()
    {

        return use;
    }
};

class LRU
{

private:
    unordered_map<string, Node*> data;
    Node* head;
    Node* tail;

    int len;
    int capacity;
public:
    LRU(int _capacity) : len(0), capacity(_capacity)
    {

        head = new Node();
        tail = new Node();

        head->SetNext(tail);
        tail->SetPrev(head);
    }


    int GetRet(string& _str)
    {

        if (!data.count(_str))
        {

            Node* temp = new Node();
            data[_str] = temp;
        }

        // 데이터 추가 확인
        int ret = 5;
        // 캐시에 데이터가 없는지 확인
        if (!data[_str]->Use()) len++;
        // 캐시에 데이터가 존재
        else ret = 1;

        data[_str]->Connect(head);

        // 캐시가 가득차서 빼야하는지 확인
        // 원래는 가득 찼는지 확인해야 하지만,
        // linked list로 자료구조를 선정해서 뒤에 연산해도 이상없다
        if (capacity < len)
        {

            tail->GetPrev()->DisConnect();
            len--;
        }

        return ret;
    }
};

void SetString(vector<string>& cities)
{

    for (string& str : cities)
    {

        for (int i = 0; i < str.length(); i++)
        {

            int c = str[i];
            // 대문자를 소문자로 변환!
            if ('A' <= c && c <= 'Z')
            {

                c = c - 'A' + 'a';
                str[i] = c;
            }
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    SetString(cities);
    LRU lru(cacheSize);

    for (string& str : cities)
    {

        answer += lru.GetRet(str);
    }

    return answer;
}