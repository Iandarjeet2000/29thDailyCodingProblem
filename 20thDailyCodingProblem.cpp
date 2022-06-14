
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int intersectPoint(Node* head1, Node* head2)
{
   int m=0,n=0;
   Node *t1=head1,*t2=head2;
   while(t1!=NULL)
   {
       t1=t1->next;
       ++m;
   }
   while(t2!=NULL)
   {
       t2=t2->next;
       ++n;
   }
   if(m>n)
   {
       int t=m-n;
       while(t--)
       head1=head1->next;
   }
   else
   {
       if(m<n)
       {
           int t=n-m;
           while(t--)
           head2=head2->next;
       }
   }
   while(head1!=NULL&&head2!=NULL)
   {
       if(head1==head2)
       return head1->data;
       head1=head1->next;
       head2=head2->next;
   }
   return -1;
}
