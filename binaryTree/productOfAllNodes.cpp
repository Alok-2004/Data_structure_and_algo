#include<iostream>

using namespace std;

class TreeNode{
  public:
  	long long val;
  	TreeNode *left;
  	TreeNode *right;
  	
  	TreeNode(long long val){
  		this->val = val;
  		this->left = NULL;
  		this->right = NULL;
	  }
};

long long product(TreeNode *root){
	if(root == NULL)  return 1;
	long long ans = root->val * product(root->left) * product(root->right);
	return ans;
}

int main(){
  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(3);
  TreeNode *d = new TreeNode(4);
  TreeNode *e = new TreeNode(5);
  TreeNode *f = new TreeNode(6);
  TreeNode *g = new TreeNode(7);
  
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->left = g;
  
  cout<< "sProduct of all the Nodes are "<< product(a);
  
}
