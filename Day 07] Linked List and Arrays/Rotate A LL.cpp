#include <bits/stdc++.h>

Node *rotate(Node *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    while (k--)
    {
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }
    return head;
}