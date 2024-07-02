#include<iostream>

using namespace std;

class Solution {
public:
  
  bool helper(TreeNode *p, TreeNode *q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    if(p->val == q->val ){
        return helper(p->left, q->right) && helper(p->right, q->left);
    }
    else return false;
  }

  bool isSymmetric(TreeNode* root) {
    bool ans = helper(root->left, root->right);
    return ans;        
  }
};
