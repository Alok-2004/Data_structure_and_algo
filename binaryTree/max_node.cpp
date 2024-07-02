#include<iostream>
#include<algorithm>
#include<climits>
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

int maxNode(Node *root){
	if(root == NULL)  return INT_MIN;
	int mx = max(root->val, maxNode(root->left));
	mx = max(mx, maxNode(root->right));
	return mx;
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
	
	cout<<maxNode(a);
}
