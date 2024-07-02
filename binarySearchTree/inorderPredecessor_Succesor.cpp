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

TreeNode* inorderPredecessor(TreeNode* root){
    if(root->left == NULL) return NULL;
    TreeNode* pred = root->left;
    while(pred->right != NULL){
        pred = pred->right;
    }
    return pred;
}

TreeNode* inorderSuccessor(TreeNode* root){
    if(root->right == NULL) return NULL;
    TreeNode* pred = root->right;
    while(pred->left != NULL){
        pred = pred->left;
    }
    return pred;
}