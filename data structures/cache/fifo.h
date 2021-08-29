#include "queue.h"
class FIFO : public Queue
{
public:
    void printCacheStatus()
    {
        if (isEmpty())
        {
            cout << "Page Cache Empty\n\n";
        }
        else
        {
            cout << "Current State of the Page Cache :  ";
            long long *q_arr = this->getQueueArray();
            for (int i = 0; i < MAX_SIZE; i++)
            {
                cout << q_arr[i] << " ";
            }
            cout << "\n\n";
        }
    }
    bool getPage(long long page_val)
    {
        long long *q_arr = this->getQueueArray();
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (q_arr[i] == page_val)
                return true;
        }
        if (this->IsFull())
            this->deque_element();
        this->enque(page_val);
        return false;
    }
    void checkCache(long long page_val)
    {
        if (this->getPage(page_val))
        {
            cout << "Cache Hit\n";
        }
        else
        {
            cout << "Cache Miss\n";
        }
    }
};