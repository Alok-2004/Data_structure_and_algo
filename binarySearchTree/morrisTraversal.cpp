// Morris Traversal(iterative inorder traversal with SC of O(1)) = inorder Traversal
// But issue is with other traversal method is that they have SC of O(n) 

#include<iostream>
#include<climits>
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