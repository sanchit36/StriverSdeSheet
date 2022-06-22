#include <bits/stdc++.h>
/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *l1, Node<int> *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    Node<int> *head = NULL, *tail = NULL;
    if (l1->data < l2->data)
    {
        head = l1;
        tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        tail = l2;
        l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }

    if (l1 == NULL)
        tail->next = l2;
    else
        tail->next = l1;

    return head;
}
