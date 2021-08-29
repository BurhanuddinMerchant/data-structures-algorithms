#include "fifo.h"
#include "lru.h"
#include "optimal.h"

void lru()
{
    int memory_size, cache_size, opt, k;
    cout << "\n\n\t\t\t\tLRU Page Replacement Algorithm \n\n";
    cout << "Enter memory size : ";
    cin >> memory_size;
    memory_size = normalize(memory_size, 100);
    initializeMemory(memory_size);
    cout << "\n";
    cout << "Configure Cache size : ";
    cin >> cache_size;
    cout << "\n\n";
    LRU<int, string> lru(normalize(cache_size, 3));
    while (1)
    {
        cout << "Choices : 1] Get Page  2] Print Cache Status 3] Exit\n\n";
        cout << "Your Choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the page key : ";
            cin >> k;
            while (k >= memory_size)
            {
                cout << "Enter valid page key : ";
                cin >> k;
            }
            cout << "\nValue : | " << lru.getValueFromCache(k) << " |\n\n";
            break;
        }
        case 2:
        {
            cout << "Current Cache State : \n";
            lru.printCacheState();
            break;
        }
        case 3:
        {
            cout << "Thank You!";
            return;
        }
        default:
        {
            cout << "Enter valid option\n\n";
            break;
        }
        }
    }
    return;
}

void fifo()
{
    cout << "\n\n\t\t\t\tFIFO Page Replacement Algorithm \n\n";
    FIFO fifo;
    int opt, k;
    while (1)
    {
        cout << "Choices : 1] Get Page  2] Print Cache Status 3] Exit\n\n";
        cout << "Your Choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the page key : ";
            cin >> k;
            fifo.checkCache(k);
            break;
        }
        case 2:
        {
            cout << "Current Cache State : \n";
            fifo.printCacheStatus();
            break;
        }
        case 3:
        {
            cout << "Thank You!";
            return;
        }
        default:
        {
            cout << "Enter valid option\n\n";
            break;
        }
        }
    }
    return;
}
void optimal()
{
    cout << "\n\n\t\t\t\tOptimal Page Replacement Algorithm \n\n";
    int inputs[10] = {1, 2, 3, 4, 5, 6, 4, 3, 2, 1};
    Optimal optimal(inputs, 10);
    int opt, k;
    while (1)
    {
        cout << "Choices : 1] Get Page  2] Print Cache Status 3] Exit\n\n";
        cout << "Your Choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the page key : ";
            cin >> k;
            optimal.getValueFromCache(k);
            break;
        }
        case 2:
        {
            cout << "Current Cache State : \n";
            optimal.printCacheState();
            break;
        }
        case 3:
        {
            cout << "Thank You!";
            return;
        }
        default:
        {
            cout << "Enter valid option\n\n";
            break;
        }
        }
    }
    return;
}
int main()
{
    cout << "\n\n\t\t\t\tPage Replacement Algorithms ";
    while (1)
    {
        cout << "Algorithms : 1] FIFO    2] LRU    3] Optimal   4] Exit\n\n";
        int opt;
        cout << "Enter option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            fifo();
            break;

        case 2:
            lru();
            break;
        case 3:
            optimal();
            break;
        case 4:
            cout << "Thank You!\n";
            return 0;
        default:
            cout << "Enter valid option!\n";
            break;
        }
    }
    return 0;
}