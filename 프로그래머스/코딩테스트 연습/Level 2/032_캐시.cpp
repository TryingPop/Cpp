/*
��¥ : 2024. 7. 9
�̸� : �輺��
���� : ĳ��
    ĳ�� ũ��(cacheSize)�� �����̸� �迭(cities)�� �Է� �޴´�
    cacheSize�� 0�̻� 30������ �����̸�,
    cities�� �����̸����� �ִ� ���� ���� 10���� �̴�
    �� ���� �̸��� ����, ����, Ư������ ���� ���� �����ڷ� �����Ǿ� ������
    ��ҹ��� ������ ���� �ʴ´�
    ���� �̸��� �ִ� 20�ڷ� �̷���� �ִ�

    ���� �̸� �迭�� ������� ó���� �� �� ����ð��� ���ؾ��Ѵ�
    ĳ�� ��ü �˰����� LRU(Least Recently Used)�� ����Ѵ�
    cache hit�� ��� ����ð��� 1�̴�
    cache miss�� ��� ����ð��� 5�̴�


    parameter
    3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "NewYork" }


    return
    26


    sol
    ĳ�ÿ� ����� �����ʹ� ���� Jeju�� �߰��ؾ��Ѵ�
    �׷��� cache miss�� ����ð� 5�̴�
    ĳ�� : Jeju

    ĳ�ÿ� Pangyo�� ����Ǿ� ���� �����Ƿ� �߰��ؾ��Ѵ�
    �׷��� cache miss�� ����ð��� 5�̴�
    ĳ�� : Pangyo, Jeju

    ĳ�ÿ� Seoul�� ����Ǿ��� ���� �����Ƿ� Seoul�� �߰��ؾ� �Ѵ�
    �׷��� cache miss�� ����ð��� 5�̴�
    ĳ�� : Seoul, Pangyo, Jeju

    ĳ�ÿ� Jeju�� ����Ǿ��� �ִ�
    �׷��� cache hit�� ����ð��� 1�̴�
    ĳ�� : Jeju, Seoul, Pangyo

    ...

    �̷��� �����ϴٰ�
    NewYork�� ����
    ĳ�� : Seoul, Pangyo, Jeju
    �̹Ƿ� ���� ĳ�ô� ���� �� �ְ�, NewYork�� ĳ�ÿ� ���� �ʴ�
    ���� �������� ����� Jeju�� ���� NewYork�� �ִ´�
    �׷��� cache miss�� ����ð��� 5�̴�
    ĳ�� : NewYork, Seoul, Pangyo

    �̷��� ���ϸ�
    { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "NewYork" }
    { 5,        5,      5,          1,      1,      1,      1,      1,          1,      5 }
    �� �ð��� �ɸ��� ��ü 26�� �ð��� �ȴ�
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

        // ��� �ձ�
        // �� üũ �ؾ��ϳ� ���ߴ�
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

        // ������ �߰� Ȯ��
        int ret = 5;
        // ĳ�ÿ� �����Ͱ� ������ Ȯ��
        if (!data[_str]->Use()) len++;
        // ĳ�ÿ� �����Ͱ� ����
        else ret = 1;

        data[_str]->Connect(head);

        // ĳ�ð� �������� �����ϴ��� Ȯ��
        // ������ ���� á���� Ȯ���ؾ� ������,
        // linked list�� �ڷᱸ���� �����ؼ� �ڿ� �����ص� �̻����
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
            // �빮�ڸ� �ҹ��ڷ� ��ȯ!
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