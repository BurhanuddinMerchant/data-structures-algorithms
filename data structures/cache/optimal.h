#include <bits/stdc++.h>
#define MAX_SIZE 3
using namespace std;
class Optimal
{
    map<int, int> cache;
    int cache_fill;
    int *future_inputs;
    int future_input_size;
    int input_state;

public:
    Optimal(int *inputs, int input_size) : cache_fill(0), future_inputs(inputs), future_input_size(input_size), input_state(0) {}
    int getValueFromCache(int v)
    {
        if (cache[v])
        {
            // cache hit
        }
        else if (cache_fill < MAX_SIZE)
        {
            // cache miss
            cache[v] = v;
            cache_fill++;
        }
        else
        {
            // cache miss
            removeLeastRecentlyReferencedInFuture();
            cache[v] = v;
        }
        input_state++;
        return cache[v];
    }
    void removeLeastRecentlyReferencedInFuture()
    {
        vector<int> v(cache.size());
        int i = 0;
        int input_state_cpy = input_state;
        for (map<int, int>::iterator itr = cache.begin(); itr != cache.end(); ++itr)
        {
            v.at(i) = itr->first;
            i++;
        }
        while (v.size() != 1 && input_state_cpy < future_input_size)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v.at(j) == future_inputs[input_state])
                {
                    v.erase(v.begin() + j);
                    break;
                }
            }
            input_state_cpy++;
        }
        this->cache.erase(v.at(0));
        map<int, int> new_cache;
        for (map<int, int>::iterator itr = cache.begin(); itr != cache.end(); ++itr)
        {
            if (itr->second)
            {
                new_cache[itr->first] = itr->second;
            }
        }
        cache = new_cache;
    }
    void printCacheState()
    {
        if (cache_fill == 0)
        {
            cout << "|----| Empty |----|\n";
            return;
        }
        for (std::map<int, int>::iterator it = cache.begin(); it != cache.end(); ++it)
        {
            cout << "----| " << it->first << " |----";
        }
        cout << endl;
    }
};