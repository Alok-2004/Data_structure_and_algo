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

class Solution {
public:
    void helper(TreeNode* root, long long sum, int& count, int targetSum){
        if(root == NULL) return;
        sum += root->val;
        if(targetSum == sum){
            count++;
        }
        // Continue traversing even after finding a valid path
        helper(root->left, sum, count, targetSum);
        helper(root->right, sum, count, targetSum);
    }


    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        int count = 0;
        helper(root, 0, count, targetSum);
        count += (pathSum(root->left, targetSum) + pathSum(root->right, targetSum));
        return count;
    }
};