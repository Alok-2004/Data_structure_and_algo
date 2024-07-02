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

TreeNode* helper(vector<int>& arr, int lo, int hi ){
	if(lo > hi) return NULL;
	int mid = lo + (hi - lo)/2;
	TreeNode* root = new TreeNode(arr[mid]);
	root->left = helper(arr, lo, mid-1);
	root->right = helper(arr, mid + 1, hi);
	return root;
}

TreeNode* sortedArrayToBST(vector<int>&arr){
    int n = arr.size();
	return helper(arr, 0, n-1);
}