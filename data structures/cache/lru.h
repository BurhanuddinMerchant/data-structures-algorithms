#include <bits/stdc++.h>
vector<pair<int, string>> memory;
void initializeMemory(int size)
{
    for (int i = 0; i < size; i++)
    {
        string s;
        stringstream ss;
        ss << i;
        ss >> s;
        memory.push_back({i, "page " + s});
    }
}
int normalize(int n, int def_val)
{
    if (n <= 0)
        return def_val;
    else
        return n;
}
template <typename K, typename V>
class DLNode
{
    DLNode *next, *prev;
    K key;
    V val;

public:
    // constructors
    DLNode() : next(nullptr), prev(nullptr), key(0), val(0) {}
    DLNode(K k, V v) : next(nullptr), prev(nullptr), key(k), val(v) {}
    DLNode(DLNode *n, DLNode *p, K k, V v) : next(n), prev(p), key(k), val(v) {}

    // getters
    V getVal() { return this->val; }
    K getKey() { return this->key; }
    DLNode *getNext() { return this->next; }
    DLNode *getPrev() { return this->prev; }

    // setters
    void setVal(V v) { this->val = v; }
    void setKey(K k) { this->key = k; }
    void setNext(DLNode *n) { this->next = n; }
    void setPrev(DLNode *p) { this->prev = p; }

    V getValFromKey(K k) { return this->val; }
};
template <typename K, typename V>
class LRU
{
    map<K, DLNode<K, V> *> lru_map;
    DLNode<K, V> *lru_queue_front, *lru_queue_rear;
    int cache_fill_size;
    int cache_size;

public:
    LRU() : lru_queue_front(nullptr), lru_queue_rear(nullptr), cache_fill_size(3) {}
    LRU(int size) : lru_queue_front(nullptr), lru_queue_rear(nullptr), cache_fill_size(size), cache_size(size) {}
    V getValueFromCache(K k)
    {
        if (lru_map.find(k) != lru_map.end())
        {
            // cache hit , update the lru_queue status
            DLNode<K, V> *cachedNode = lru_map[k];
            if (cache_fill_size == 0)
            {

                if (cachedNode == lru_queue_front)
                {
                    lru_queue_front = cachedNode->getPrev();
                    lru_queue_front->setNext(nullptr);
                    cachedNode->setPrev(nullptr);
                    cachedNode->setNext(lru_queue_rear);
                    lru_queue_rear->setPrev(cachedNode);
                    lru_queue_rear = cachedNode;
                }
                else
                {
                    cachedNode->getPrev()->setNext(cachedNode->getNext());
                    cachedNode->getNext()->setPrev(cachedNode->getPrev());
                    cachedNode->setPrev(nullptr);
                    cachedNode->setNext(lru_queue_rear);
                    lru_queue_rear->setPrev(cachedNode);
                    lru_queue_rear = cachedNode;
                }
            }
            else if (cache_size - cache_fill_size == 2)
            {
                // case where two nodes are present , the required node is definitely at the front of the queue
                cachedNode->setPrev(nullptr);
                cachedNode->setNext(lru_queue_rear);
                lru_queue_rear->setPrev(cachedNode);
                lru_queue_rear->setNext(nullptr);
                lru_queue_front = lru_queue_rear;
                lru_queue_rear = cachedNode;
            }
            else if (cachedNode == lru_queue_front)
            {
                cachedNode->getPrev()->setNext(nullptr);
                lru_queue_front = cachedNode->getPrev();
                cachedNode->setPrev(nullptr);
                cachedNode->setNext(lru_queue_rear);
                lru_queue_rear->setPrev(cachedNode);
                lru_queue_rear = cachedNode;
            }
            else
            {
                // where more than 2 but less than ${size} nodes are present
                cachedNode->getPrev()->setNext(cachedNode->getNext());
                cachedNode->getNext()->setPrev(cachedNode->getPrev());
                cachedNode->setPrev(nullptr);
                cachedNode->setNext(lru_queue_rear);
                lru_queue_rear->setPrev(cachedNode);
                lru_queue_rear = cachedNode;
            }
            return cachedNode->getVal();
        }
        else
        {
            // cache miss search main memory and insert into cache
            V page;
            for (int i = 0; i < memory.size(); i++)
            {
                if (memory.at(i).first == k)
                {
                    page = memory.at(i).second;
                }
            }
            DLNode<K, V> *new_node = new DLNode<K, V>(k, page);
            if (lru_queue_front == lru_queue_rear && lru_queue_front == nullptr)
            {
                this->lru_queue_front = new_node;
                this->lru_queue_rear = new_node;
                lru_map[k] = new_node;
                cache_fill_size--;
            }
            else if (cache_fill_size == 0)
            {
                DLNode<K, V> *temp_front = this->lru_queue_front;
                this->lru_queue_front = this->lru_queue_front->getPrev();
                this->lru_queue_front->setNext(nullptr);
                lru_map.erase(temp_front->getKey());
                delete temp_front;
                new_node->setNext(lru_queue_rear);
                new_node->setPrev(nullptr);
                lru_queue_rear->setPrev(new_node);
                lru_queue_rear = new_node;
                lru_map[k] = new_node;
            }
            else
            {

                new_node->setNext(lru_queue_rear);
                new_node->setPrev(nullptr);
                lru_queue_rear->setPrev(new_node);
                lru_queue_rear = new_node;
                lru_map[k] = new_node;
                cache_fill_size--;
            }
            return new_node->getVal();
        }
    }
    void printCacheState()
    {
        DLNode<K, V> *temp = lru_queue_rear;
        cout << "\nRear : |----|";
        if (lru_queue_rear == lru_queue_front && lru_queue_front == nullptr)
            cout << "Empty |----|";
        while (temp != nullptr)
        {
            cout << temp->getVal() << "|----|";
            temp = temp->getNext();
        }
        cout << " : Front\n\n";
    }
};