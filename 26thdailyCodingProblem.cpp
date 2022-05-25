/* Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass. */

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct Node* create(struct Node* head, int x)
{
    struct Node *temp, *ptr = head;
    temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}
Node* removeKthFromEnd(Node* head, int k)
{
        Node *start = new Node();
        start -> next = head;
        Node* fastPtr = start;
        Node* slowPtr = start;
        for(int i = 0; i < k; i++){
          fastPtr = fastPtr->next;
        }
        while(fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        slowPtr->next = slowPtr->next->next;
        return start->next;
}
void display(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    struct Node* head = NULL;
    head = create(head, 0);
    head = create(head, 2);
    head = create(head, 7);
    head = create(head, 4);
    head = create(head, 5);
     
    int k = 2;
     
    cout << "Linked list before modification: \n";
    display(head);
 
    head = removeKthFromEnd(head, 2);
    cout << "Linked list after modification: \n";
    display(head);
    return 0;
}