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

void insert(TreeNode* root, int val){
    if(root->left == NULL && root->val > val){
        root->left = new TreeNode(val);
        return;
    }else if(root->right == NULL && root->val < val){
        root->right = new TreeNode(val);
        return;
    }

    if(root->val > val){
        insert(root->left, val);
    }else{
        insert(root->right, val);
    } 
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
  TreeNode* root = new TreeNode(preorder[0]);
  for(int i = 1; i<preorder.size(); i++){
    insert(root, preorder[i]);
  }

  return root;      
}