#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    vector<TrieNode *> children;
    char c;

public:
    TrieNode(){};
    TrieNode(char ch) : c(ch){};
    // getters
    char getChar() { return this->c; }
    vector<TrieNode *> getChildren() { return this->children; }

    // setters
    void setChar(char c) { this->c = c; }
    void insertChildren(TrieNode *c) { this->children.push_back(c); }

    // utility
    TrieNode *checkIfCharacterIsInChild(int c)
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            if (children.at(i)->c == c)
            {
                return children.at(i);
            }
        }
        return nullptr;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(nullptr) {}
    void insertString(string s)
    {
        TrieNode *t = this->root;
        if (this->root == nullptr)
        {
            this->root = new TrieNode(s[0]);
            t = this->root;
            for (int i = 1; i < (int)s.size(); i++)
            {
                TrieNode *new_node = new TrieNode(s[i]);
                t->insertChildren(new_node);
                t = new_node;
            }
            return;
        }
        int i;
        for (i = 0; i < (int)s.size(); i++)
        {
            TrieNode *child_node = t->checkIfCharacterIsInChild(s[i]);
            if (child_node == nullptr)
            {
                break;
            }
            else
            {
                t = child_node;
            }
        }
        if (i == s.size())
        {
            return;
        }
        else
        {
            for (int j = i; j < (int)s.size(); j++)
            {
                TrieNode *new_node = new TrieNode(s[j]);
                t->insertChildren(new_node);
                t = new_node;
            }
        }
        return;
    }
};

int main()
{
    cout << "here";
    Trie t;
    t.insertString("Helo");
    return 0;
}