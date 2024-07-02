class Solution {
public:

    void swapHelper(TreeNode* root){
        if(!root) return;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        swapHelper(root->right);
        swapHelper(root->left);
    }

    TreeNode* invertTree(TreeNode* root) {
        swapHelper(root);
        return root;
    }
};
