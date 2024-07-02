#include<iostream>
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

void sum(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> ans, int s) {
    if (root == NULL) return;
    s += root->val;
    ans.push_back(root->val);

    if (targetSum == s && root->left == NULL && root->right == NULL) {
        res.push_back(ans);
        return;
    }

    sum(root->left, targetSum, res, ans, s);
    sum(root->right, targetSum, res, ans, s);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> ans;
    sum(root, targetSum, res, ans, 0);
    return res;
}


int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
}