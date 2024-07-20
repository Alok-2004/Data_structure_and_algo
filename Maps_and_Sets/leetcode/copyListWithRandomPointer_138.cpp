#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1 -> Create the deep copy without random pointer
        Node* dummy = new Node(0);
        Node* tempC = dummy;
        Node* temp = head;

        while(temp) {
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }

        Node* b = dummy->next;
        Node* a = head;

        // Step 2 -> Make a map<original, duplicate>
        unordered_map<Node*, Node*> m;
        Node* tempa = a;
        Node* tempb = b;
        while(tempa != NULL) {
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }

        // Step 3 -> Assign the random pointers
        for(auto x : m) {
            Node* o = x.first;
            Node* d = x.second;
            if(o->random != NULL) {
                d->random = m[o->random];
            }
        }

        return b;
    }
};
