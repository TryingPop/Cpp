#include <cstdlib>
#include <unordered_map>

#define CACHE_HIT 1
#define CACHE_MISS 5

using namespace std;

template <typename T> class Node
{

private:
    Node* prev; // ���� ���
    Node* next; // ���� ���
    T key;      // ��尡 ����Ű�� ����
    bool use;   // ���� ��� ����

public:
    Node() : use(false), prev(NULL), next(NULL) { }

    void Connect(Node* _head)
    {

        // ��� �ձ�
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

        // ��� ����
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
    unordered_map<T, Node<T>*> data;    // ���ҿ� �ش��ϴ� ��� ��������� Ȯ��
    Node<T>* head;                      // �տ� �̾� ���̱� �뵵
    Node<T>* tail;                      // ������ ��� �� �뵵

    Node<T>* pool;                      // ��Ȱ��

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
        
        �뷮 Ȯ��
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
        
        ��� ����
        */

        Node<T>* remove = data[_ele];

        data.erase(remove->GetKey());
        remove->DisConnect();

        // �����Ѱ� pool�� ������ִٸ� ����
        if(pool == NULL) pool = remove;
    }

    void Add(const T& _ele) 
    {

        if (data.count(_ele)) 
        {

            // �̹� �ִ°Ÿ� ������ �̵����Ѵ�
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
        
        ĳ�� ��Ʈ����, ĳ�� �̽����� ��ȯ�Ѵ�
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