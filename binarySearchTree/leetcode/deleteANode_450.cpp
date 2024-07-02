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

/*
Three cases
1. Leaf node
2. Node with one child
3. Node with two child
*/

//Solution

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

TreeNode* deleteNode(TreeNode* root, int key){
	if(root == NULL) return root;
	if(root->val == key){ 
	
		// for case 1: Leaf Node
		if(root->right == NULL && root->left == NULL) return NULL;
		else if(root->right == NULL || root->left == NULL){
			// for case 2: One child 
			if(root->left) return root->left;
			else return root->right;
		}
		// Case 3: Two children
        else {
            // Replace with in-order predecessor/inorder successor
            TreeNode* pred = inorderPredecessor(root);
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val);
        }

	}
	else if(root->val > key){
		root->left = deleteNode(root->left, key);
	}else{
		root->right = deleteNode(root->right, key);
	}
	return root;
}