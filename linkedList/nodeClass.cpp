#include<iostream>
using namespace std;

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

int main()
{
    Node a(10);
    Node e(20);
    Node c(50);
    Node b(40);

    // Forming ll;
    a.next = &b;
    b.next = &c;
    c.next = &e;
    e.next = NULL;

    //a.next->val = 3223;
    cout<<b.val<<endl;
    cout<<(a.next)->next->val<<endl;

    Node temp = a;
    // while(temp.next != NULL){   // But this will not print the value of last node
    //     cout<<temp.val<<" ";
    //     temp = *(temp.next);
    // } 

    while(1){   // But this will not print the value of last node
        cout<<temp.val<<" ";
        if(temp.next == NULL)  break;  
        temp = *(temp.next);
    }   
}
