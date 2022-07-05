#include <bits/stdc++.h>
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (head == NULL)
        return NULL;
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> m;
    LinkedListNode<int> *temp = head;

    while (temp != NULL)
    {
        LinkedListNode<int> *copy = new LinkedListNode<int>(temp->data);
        m[temp] = copy;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        m[temp]->next = m[temp->next];
        m[temp]->random = m[temp->random];
        temp = temp->next;
    }

    return m[head];
}
