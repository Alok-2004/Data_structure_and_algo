/*
Condition
1. Complete binary Tree(check via bool function)
2. All descendent must be smaller(true for each sub tree)
    root->val > root->right-> val and same for left
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int sizeOf(Node* root){
    if (root == nullptr) return 0;
    return 1 + sizeOf(root->left) + sizeOf(root->right);
}

bool isMax(Node* root){
    if(root == nullptr) return true;
    if( root->left  != nullptr and root -> val < root-> left-> val) return false;
    if( root->right  != nullptr and root -> val < root-> right-> val) return false;
    bool left = isMax(root->left);
    bool right = isMax(root->right);
    return left and right;
}

bool isCBT(Node* root){

    bool flag = true;
    int s = sizeOf(root);
    int count = 0;
    queue<Node*> q;
    q.push(root);
    while(count < s){
        Node* temp = q.front();
        q.pop();
        count++;
        if(temp != nullptr){ 
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    while(!q.empty()){
        Node* temp = q.front();
        if(temp != nullptr){
            flag = false;
            break;
        }
        q.pop();
    }
    return flag;
}

int main(){
    Node *a = new Node(20); // root
    Node *b = new Node(15);
    Node *c = new Node(10);
    Node *d = new Node(8);
    Node *e = new Node(11);
    Node *f = new Node(6);
    Node *g = nullptr;

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    if(isCBT(a) and isMax(a))  cout<<"BT is a max heap" ;
    else cout<<"BT is not a max heap";

}