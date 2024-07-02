 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:

    void inorder(TreeNode* root, vector<TreeNode*> &v){
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    TreeNode* insert(int lo, int hi, vector<TreeNode*>&v){
        if(lo > hi) return NULL;
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = v[mid];
        root->left = insert(lo, mid - 1, v);
        root->right = insert(mid + 1, hi, v);
        return root; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return;
        vector<TreeNode*>v;
        inorder(root, v);
        TreeNode* ans = insert(0, v.size() - 1, v);
        return ans;
    }
};