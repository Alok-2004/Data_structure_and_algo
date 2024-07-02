#include<iostream>
#include<algorithm>
#include<climits>
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

long long smallest(TreeNode *root){
	if(root == NULL)  return INT_MAX;
	long long ans = min(root->val,  min(smallest(root->left) , smallest(root->right)));
	return ans;
}

int main(){
  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(-214748364823);
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
  
  cout<< "Minimum Node of all the Nodes is "<< smallest(a);
  
}
