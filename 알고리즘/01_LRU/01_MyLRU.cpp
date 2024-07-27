#include <cstdlib>
#include <unordered_map>

#define CACHE_HIT 5
#define CACHE_MISS 1

using namespace std;

class Node
{

private:
    bool use;   // 현재 사용 여부
    Node* prev; // 이전 노드
    Node* next; // 다음 노드

public:
    Node() : use(false), prev(NULL), next(NULL) { }

    void Connect(Node* _head)
    {

        // 노드 잇기
        // 널 체크 확인하면 안정성 올라간다
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


template <typename T> class LRU
{

private:
    unordered_map<T, Node*> data;   // 원소에 해당하는 노드 사용중인지 확인
    Node* head;                     // 앞에 이어 붙이기 용도
    Node* tail;                     // 마지막 노드 뺄 용도

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

    void RegisterNode(T& _ele)
    {

        // data에 등록된 노드인지 확인
        // 없다면 생성
        if (data.count(_ele)) return;

        Node* temp = new Node();
        data[_ele] = temp;
    }

    void ChkLength() 
    {

        // 캐시가 가득차서 빼야하는지 확인
        // 원래는 가득 찼는지 확인해야 하지만,
        // linked list로 자료구조를 선정해서 뒤에 연산해도 이상없다
        if (capacity >= len) return;

        tail->GetPrev()->DisConnect();
        len--;
    }

    int AddData(T& _ele)
    {

        RegisterNode(_ele);

        // 데이터 추가 확인
        int ret = CACHE_HIT;
        // 캐시에 데이터가 없는지 확인
        if (!data[_ele]->Use()) len++;
        // 캐시에 데이터가 존재
        else ret = CACHE_MISS;

        // 해당 데이터 맨 앞으로
        data[_ele]->Connect(head);

        ChkLength();

        // 캐시 히트인지 캐시 미스인지 반환
        return ret;
    }
};