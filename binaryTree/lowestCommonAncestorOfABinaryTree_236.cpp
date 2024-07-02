#include<iostream>
#include<vector>

class Solution {
public:
  bool existsInTree(TreeNode* root, TreeNode* target){
  	if(root == target) return true;
  	if(root == NULL) return false;
  	return existsInTree(root->left, target) || existsInTree(root->right, target);
  }
	
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q)  return root;      
    else if( existsInTree(root->left, p) && existsInTree(root->right, q))  return root;      
    else if( !existsInTree(root->left, p) && !existsInTree(root->right, q))  return root;
    else if( existsInTree(root->left, p) && !existsInTree(root->right, q))  return lowestCommonAncestor(root->left,p, q);
    else return lowestCommonAncestor(root->right,p, q);
  }
};
