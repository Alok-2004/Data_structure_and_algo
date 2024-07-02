#include<iostream>
#include<algorithm>
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

int getHeight(TreeNode* root){
 if(root == NULL) return 0;
 int ans = 1+ max(getHeight(root->left), getHeight(root->right));
 return ans; 
}

bool isBalanced(TreeNode* root) {
  if( root == NULL ) return true;
  int l = getHeight(root->left);
  int r = getHeight(root->right);
  
  if(abs(l - r) > 1) return false;
  isBalanced(root->left);
  isBalanced(root->right);       
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
  
  cout<< isBalanced(a);
  
}
