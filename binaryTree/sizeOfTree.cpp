// Size of the tree/number of nodes
#include<iostream>
using namespace std;

class Node{
  public:
	int val;
	Node *left;
	Node *right;
	
	Node(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}  
};

int sum(Node *root){
    if(root == NULL) return 0;
    int ans = 1 + sum(root->left) + sum(root->right);
    return ans;
}

int main(){
	Node *a = new Node(1);
	Node *b = new Node(7);
	Node *c = new Node(6);
	Node *d = new Node(5);
	Node *e = new Node(4);
	Node *f = new Node(3);
	Node *g = new Node(2);
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

    cout<<sum(a)<<endl;
}
