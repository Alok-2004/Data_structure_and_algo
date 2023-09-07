#include<iostream>
using namespace std;
/*
Benifit of using pointer instead of dot operater is in traversing
*/
class Node // Linked list node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* head)
{
    Node* temp = head; // This will store address of node a
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;  //this will temp as address of next node
    }
    cout<<endl;
}

int size(Node* head)
{
    Node* temp = head; // This will store address of node a
    int n = 0;
    while(temp!=NULL)
    {
        n = n+1;
        temp = temp->next;  //this will temp as address of next node
    }
    return n;
}

int main()
{
    // a is pointer pointing towards address of node(10), new is dynamically allocating memory.
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next = b;// a->next means (*a).next = b where b is address of node b;
    b->next = c;
    c->next = d;

    display(a);
    cout<<size(a);
}