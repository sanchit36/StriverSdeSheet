#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (!head)
        return NULL;
    LinkedListNode<int> *cur = head, *prev = NULL;
    while (cur != NULL)
    {
        LinkedListNode<int> *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}