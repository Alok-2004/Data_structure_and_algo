#include<iostream>
class Solution {
public:
  void helper(TreeNode* root, string str, vector<string>&ans){
    if(root == NULL) return;
    string a = to_string(root->val);
    if(root->right == NULL && root->left == NULL){
        ans.push_back(str + a);
        return;
    }
    helper(root->left, str + a + "->" , ans);
    helper(root->right, str + a + "->" , ans);
  } 

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>ans;
    helper(root, "", ans);
    return ans;
  }
};
