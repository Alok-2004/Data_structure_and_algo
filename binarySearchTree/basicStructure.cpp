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

TreeNode* insertIntoBST(TreeNode* root, int h){
    if(root == NULL) return new TreeNode(h);
    if(root->val > h){
        if(root->left == NULL){
            root->left = new TreeNode(h);
            return root;
        }else  insertIntoBST(root->left, h);
    }else{
        if(root->right == NULL){
            root->right = new TreeNode(h);
            return root;
        }else  insertIntoBST(root->right, h);
    }
    return root;
}


int main(){
    TreeNode* a = new TreeNode(34);
    insertIntoBST(a, 3);
    insertIntoBST(a, 1);
    insertIntoBST(a, 4);
    insertIntoBST(a, 6);
    insertIntoBST(a, -1);
    insertIntoBST(a, 9);
    insertIntoBST(a, 7);
    insertIntoBST(a, 2);

    return 0;
}