#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
    unordered_map<int, Node *> keyNode;
    unordered_map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

    void updateFreqListMap(Node *node)
    {
        // delete key Node*
        keyNode.erase(node->key);
        // delete the node in DLL
        freqListMap[node->cnt]->removeNode(node);

        // if after deleting DLL is empty and cnt == minFreq inc it
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        // update node details
        node->cnt += 1;
        // create new List for higher Freq
        List *nextHigherFreqList = new List();
        // check if already exists
        if (freqListMap.find(node->cnt) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt];
        }
        // add the node in that list
        nextHigherFreqList->addFront(node);
        // update maps
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
            return;
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
