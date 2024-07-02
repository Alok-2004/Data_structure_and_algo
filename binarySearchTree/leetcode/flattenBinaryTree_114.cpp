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

// M1
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* rightSubtree = root->right;
        root->right = root->left;
        root->left = NULL;

        TreeNode* temp = root;
        while (temp->right != NULL) temp = temp->right;
        temp->right = rightSubtree;
    }
};

//Morris traversal
