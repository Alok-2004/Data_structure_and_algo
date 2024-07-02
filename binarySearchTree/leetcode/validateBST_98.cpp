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
/*

Method 1

long long maxTree(TreeNode* root){
    if(root == NULL) return LLONG_MIN;
    return max((long long)(root->val), max(maxTree(root->left), maxTree(root->left)))
}

long long minTree(TreeNode* root){
    if(root == NULL) return LLONG_MAX;
    return min((long long)(root->val), min(minTree(root->left), minTree(root->left)))
}

bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    else if(root->val <= minTree(root->left)) return false;
    else if( root->val >= maxTree(root->right) ) return false;
    else( isValidBST(root->left) && isValidBST(root->right) );
}
*/

// Method 2
//Check for inorder Traversal as it is sorted order

void inorder(TreeNode* root, vector<int>& temp){
    if(root == NULL) return;
    inorder(root->left, temp);
    temp.push_back(root->val);
    inorder(root->right, temp);
}
bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    vector<int>temp;
    inorder(root, temp);
    for(int i = 1; i<temp.size(); i++){
        if(temp[i-1] >= temp[i]) return false;
    }
    return true:
}