#include <cstdlib>
#include <unordered_map>

#define CACHE_HIT 5
#define CACHE_MISS 1

using namespace std;

class Node
{

private:
    bool use;   // ���� ��� ����
    Node* prev; // ���� ���
    Node* next; // ���� ���

public:
    Node() : use(false), prev(NULL), next(NULL) { }

    void Connect(Node* _head)
    {

        // ��� �ձ�
        // �� üũ Ȯ���ϸ� ������ �ö󰣴�
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

        // ��� ����
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
    unordered_map<T, Node*> data;   // ���ҿ� �ش��ϴ� ��� ��������� Ȯ��
    Node* head;                     // �տ� �̾� ���̱� �뵵
    Node* tail;                     // ������ ��� �� �뵵

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

        // data�� ��ϵ� ������� Ȯ��
        // ���ٸ� ����
        if (data.count(_ele)) return;

        Node* temp = new Node();
        data[_ele] = temp;
    }

    void ChkLength() 
    {

        // ĳ�ð� �������� �����ϴ��� Ȯ��
        // ������ ���� á���� Ȯ���ؾ� ������,
        // linked list�� �ڷᱸ���� �����ؼ� �ڿ� �����ص� �̻����
        if (capacity >= len) return;

        tail->GetPrev()->DisConnect();
        len--;
    }

    int AddData(T& _ele)
    {

        RegisterNode(_ele);

        // ������ �߰� Ȯ��
        int ret = CACHE_HIT;
        // ĳ�ÿ� �����Ͱ� ������ Ȯ��
        if (!data[_ele]->Use()) len++;
        // ĳ�ÿ� �����Ͱ� ����
        else ret = CACHE_MISS;

        // �ش� ������ �� ������
        data[_ele]->Connect(head);

        ChkLength();

        // ĳ�� ��Ʈ���� ĳ�� �̽����� ��ȯ
        return ret;
    }
};