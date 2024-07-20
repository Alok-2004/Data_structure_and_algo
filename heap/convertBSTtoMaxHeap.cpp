/*
2 methods
1. using inorder traversal
    1. For Max heap
        Do inorder tarvels for decreasing order and then fill bst in level order
    2. For min heap
        Do same as 1 but inorder for increasing order


2. Using preOrder Traversal   (LST > RST)
*/

// M 1 ka 1
// Reverse inorder
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

void inorder(Node* root, vector<int>& dec){
    if(root == nullptr) return;
    inorder(root->right, dec);
    dec.push_back(root->val);
    inorder(root->left, dec);
}

void preorder(Node* root, vector<int>& dec, int &i){
    if(root == nullptr) return;
    root->val = dec[i];
    i++;
    /*
    or root->val = dec[i++];
    */
    preorder(root->left, dec, i);
    preorder(root->right, dec, i);
}

void print(const vector<int> &nums) {
    for (const auto &ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
}


int main(){
    Node *a = new Node(10);
    Node *b = new Node(5);
    Node *c = new Node(16);
    Node *d = new Node(1);
    Node *e = new Node(8);
    Node *f = new Node(12);
    Node *g = new Node(20);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<int> dec;
    inorder(a, dec);

    print(dec);
    int i = 0;
    preorder(a, dec, i);
}