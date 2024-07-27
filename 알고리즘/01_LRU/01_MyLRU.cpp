#include <cstdlib>
#include <unordered_map>

#define CACHE_HIT 1
#define CACHE_MISS 5

using namespace std;

template <typename T> class Node
{

private:
    Node* prev; // 이전 노드
    Node* next; // 다음 노드
    T key;      // 노드가 가리키는 정보
    bool use;   // 현재 사용 여부

public:
    Node() : use(false), prev(NULL), next(NULL) { }

    void Connect(Node* _head)
    {

        // 노드 잇기
        if (use) DisConnect();

        Node* n = _head->next;
        if (n != NULL)
        {

            n->prev = this;
            this->next = n;
        }

        _head->next = this;
        this->prev = _head;
        
        use = true;
    }

    void DisConnect()
    {

        // 노드 끊기
        Node* n = this->next;
        Node* p = this->prev;

        this->next = NULL;
        this->prev = NULL;

        if (n != NULL) n->prev = p;
        if (p != NULL) p->next = n;

        this->use = false;
    }

    Node* GetPrev() { return this->prev; }
    Node* GetNext() { return this->next; }

    void SetKey(T _key) { this->key = _key; }
    T GetKey() { return this->key; }

    bool Use() { return use; }
};

template <typename T> class LRU
{

private:
    unordered_map<T, Node<T>*> data;    // 원소에 해당하는 노드 사용중인지 확인
    Node<T>* head;                      // 앞에 이어 붙이기 용도
    Node<T>* tail;                      // 마지막 노드 뺄 용도

    Node<T>* pool;                      // 재활용

    int len;
    int capacity;

    Node<T>* Pooling()
    {

        if (pool == NULL) return new Node<T>();
        Node<T>* ret = pool;
        pool = NULL;
        return ret;
    }

    void ChkCapacity()
    {

        /*
        
        용량 확인
        */
        if (len <= capacity) return;

        Node<T>* remove = tail->GetPrev();
        while (capacity < len && remove != head)
        {

            Remove(remove->GetKey());
            remove = remove->GetPrev();
            len--;
        }
    }

public:
    LRU(int _capacity) : len(0), capacity(_capacity), pool(NULL)
    {

        head = new Node<T>();
        tail = new Node<T>();

        tail->Connect(head);
    }

    void Remove(const T& _ele) 
    {

        /* 
        
        노드 제거
        */

        Node<T>* remove = data[_ele];

        data.erase(remove->GetKey());
        remove->DisConnect();

        // 제거한거 pool이 비워져있다면 저장
        if(pool == NULL) pool = remove;
    }

    void Add(const T& _ele) 
    {

        if (data.count(_ele)) 
        {

            // 이미 있는거면 앞으로 이동만한다
            Node<T>* cur = data[_ele];
            cur->Connect(head);

            return;
        }

        Node<T>* add = Pooling();
        add->Connect(head);
        add->SetKey(_ele);
        data[_ele] = add;
        len++;

        ChkCapacity();
    }

    int ChkHit(const T& _ele)
    {
        
        /*
        
        캐시 히트인지, 캐시 미스인지 반환한다
        */

        if (data.count(_ele)) return CACHE_HIT;
        else return CACHE_MISS;
    }
};

#include <vector>
#include <iostream>

int main(void)
{

    vector<string> input = { "A", "B", "C", "D", "B" };
    int cacheSize = 3;
    LRU<string> lru(cacheSize);

    int answer = 0;
    for (string& str : input)
    {

        answer += lru.ChkHit(str);
        lru.Add(str);
    }

    cout << answer;                     // 21
    return 0;
}