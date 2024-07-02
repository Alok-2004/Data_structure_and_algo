#include<iostream>

using namespace std;

class Solution {
public:
    int maxDia = 0;

    int level(TreeNode* root){
        if(root == NULL) return 0;
        else return 1 + max(level(root->left) , level(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int dia = level(root->left) + level(root->right);
        maxDia = max(maxDia, dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right); 

        return maxDia;
    }
};
