#include<iostream>
using namespace std;

class TreeNode{
  public:
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}  
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
  else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->right, p, q);
  else return root;
}
