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

void leftBoundary(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;
    TreeNode* node = root;
    while (node) {
        if (node->left || node->right) {
            res.push_back(node->val);
        }
        if (node->left) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
}

void rightBoundary(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;
    TreeNode* node = root;
    while (node) {
        if (node->left || node->right) {  // Print only if it's not a leaf node
            res.push_back(node->val);
        }
        if (node->right) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
}

void bottomBoundary(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;
    if (!root->left && !root->right) {  // It's a leaf node
        res.push_back(root->val);
        return;
    }
    if (root->left) bottomBoundary(root->left, res);
    if (root->right) bottomBoundary(root->right, res);
}

void boundaryTraversal(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;

    res.push_back(root->val);
    if (root->left) {
        leftBoundary(root->left, res);
    }
    bottomBoundary(root->left, res);
    bottomBoundary(root->right, res);
    if (root->right) {
        rightBoundary(root->right, res);
    }
}

int main() {
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

    vector<int> res;
    cout << "Boundary Traversal: ";
    boundaryTraversal(a, res);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
