#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    vector<TrieNode *> children;
    char c;

public:
    TrieNode(){};
    // getters
    char getChar() { return this->c; }

    // setters
    void setChar(char c) { this->c = c; }
};

int main()
{

    return 0;
}