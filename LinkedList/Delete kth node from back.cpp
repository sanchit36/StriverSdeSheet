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

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int k)
{
    LinkedListNode<int> *dummy = new LinkedListNode<int>(1);
    LinkedListNode<int> *itr1 = dummy;
    LinkedListNode<int> *itr2 = dummy;
    dummy->next = head;
    if (head == NULL or k == 0)
        return head;
    for (int i = 0; i < k; i++)
    {
        itr1 = itr1->next;
    }
    while (itr1->next != NULL)
    {
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    itr2->next = itr2->next->next;
    return dummy->next;
}