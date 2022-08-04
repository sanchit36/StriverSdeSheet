#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    unordered_map<int, Node *> m;
    int cap;
    Node *head; // most frequent
    Node *tail; // least frequent

    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int res = resNode->value;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *exitingNode = m[key];
            m.erase(exitingNode->key);
            deleteNode(exitingNode);
        }
        else if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};
