#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

int findIntersection(Node *headA, Node *headB)
{
    Node *a = headA, *b = headB;
    while (a != b)
    {
        if (a == NULL)
            a = headB;
        else
            a = a->next;
        if (b == NULL)
            b = headA;
        else
            b = b->next;
    }
    if (a == NULL && b == NULL)
        return -1;
    return a->data;
}