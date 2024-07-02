#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
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

void reverseInorder(TreeNode* root, int &sum){
    if(root == NULL) return;
    reverseInorder(root->right, sum);
    sum += root->val;
    root->val = sum;    
    reverseInorder(root->left, sum);
}

TreeNode* bstToGST(TreeNode* root){
    int sum;
    reverseInorder(root, sum);
    return root;
}

// Reverse inorder