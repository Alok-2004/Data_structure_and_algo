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

TreeNode* searchBST(TreeNode* root, int val){
    if(root == NULL || root->val == val) return root;
    else if(root->val > val) return searchBST(root->left, val);
    else  return searchBST(root->right, val);
}

/*
Time complexity  
In best case is O(logn)
In worst case is O(n)
in average case is O(h) i.e h =  height
*/

/*
Space complexity
same as time complexity
*/