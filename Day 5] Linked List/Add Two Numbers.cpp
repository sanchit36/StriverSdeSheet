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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;
    int sum = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1)
            sum += head1->data;
        if (head2)
            sum += head2->data;
        sum += carry;
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;
        sum = 0;
    }
    if (carry)
        temp->next = new Node(carry);
    return dummy->next;
}