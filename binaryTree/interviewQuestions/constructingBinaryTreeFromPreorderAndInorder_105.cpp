#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    long long val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(long long val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


TreeNode* helper(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi) {
    if (prelo > prehi || inlo > inhi) return nullptr;

    TreeNode* root = new TreeNode(pre[prelo]);
    if (prelo == prehi) return root;

    int i = inlo;
    while (i <= inhi && in[i] != pre[prelo]) {
        i++;
    }

    int leftCount = i - inlo;

    root->left = helper(pre, prelo + 1, prelo + leftCount, in, inlo, i - 1);
    root->right = helper(pre, prelo + leftCount + 1, prehi, in, i + 1, inhi);
    
    return root;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int sz = pre.size();
    return helper(pre, 0, sz - 1, in, 0, sz - 1);
}