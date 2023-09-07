// Include all basic operation

#include <iostream>
using namespace std;

class Node 
{
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

/*
The Linkedlist class you provided is an implementation of a singly-linked list data structure in C++. 
It is designed to create and manage linked lists, 
which are a type of data structure consisting of nodes linked together where
each node contains data and a reference (or pointer) to the next node.
*/

// And since we are using head and tail pointer, so we are using another class otherwise we had to pass head and tail as tail in every function as
// arguement 
class Linkedlist 
{
private:
    Node* head;// Here *Head is pointing towards address of head 
    Node* tail;
    int size;

public:
    Linkedlist() 
    {
        head = tail = NULL;
        size = 0;
    }

    // Adding new element in begining 

    void insertAtbegin(int val) 
    {
        Node* temp = new Node(val);
        if (size == 0) 
        {
            head = tail = temp;
        }
        else 
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    // Adding new element in end 

    void insertAtEnd(int val) 
    {
        Node* temp = new Node(val);
        if (size == 0) 
        {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // Adding new element in at any position

    void insertAt(int idx, int val) 
    {
        if (idx < 0 || idx > size) 
        {
            cout << "Invalid index." << endl;
        }
        else if (idx == 0) {
            insertAtbegin(val);
        }
        else 
        {
            Node* temp = new Node(val);
            Node* current = head;
            for (int i = 0; i < idx - 1; i++) 
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            size++;
        }
    }

    // Printing element present at nth index 

    int getElement(int idx) 
    {
        if (idx < 0 || idx >= size) 
        {
            cout << "Invalid index." << endl;
            return -1;
        }

        Node* current = head;
        for (int i = 0; i < idx; i++) 
        {
            current = current->next;
        }
        return current->val;
    }

    void deleteatHead()
    {
        if(size == 0)
        {
            cout<<"Linked list is empty.";
        }
        else
        {
            head = head->next;
            size--;
        }
    }

    // To delete at tail tarverse temp till its next is tail.
    
    void deleteatTail()
    {
        if(size == 0)
        {
            cout<<"Linked list is empty.";
            return;
        }
        Node* temp = head;
        while(temp->next!=tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }

    // To delete at any index
    
    void deleteAtIndex(int idx)
    {
        if (idx < 0 || idx > size) 
        {
            cout << "Invalid index." << endl;
        }
        else if (idx == 0) {
            return deleteatHead();
        }
        else if(idx == size-1)
        {
            return deleteatTail();
        }
        else
        {
            Node* temp = head;
            for(int i = 0; i<idx-1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }

    }

    //Printing all the elements

    void display() 
    {
        Node* current = head;
        while (current != NULL) 
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Linkedlist ll;
    
    // Insert elements
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtbegin(5);
    ll.insertAt(2, 15);

    // Display the list
    cout << "Linked list: ";
    ll.display();

    // Delete elements
    ll.deleteatHead();
    ll.deleteAtIndex(2);

    // Display the modified list
    cout << "Modified linked list: ";
    ll.display();

    // Get an element by index
    int element = ll.getElement(1);
    if (element != -1) {
        cout << "Element at index 1: " << element << endl;
    }

    // Insert more elements
    ll.insertAtEnd(25);
    ll.insertAtbegin(3);

    // Display the updated list
    cout << "Updated linked list: ";
    ll.display();

    // Delete elements
    ll.deleteatTail(); // Remove the last element
    ll.deleteAtIndex(1); // Remove the element at index 1

    // Display the final list
    cout << "Final linked list: ";
    ll.display();

    return 0;
}