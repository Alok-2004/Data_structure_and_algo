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

/*

    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<int>& ans){
        if(root == NULL) return;
        if(curr == level){
            ans[level] = root->val;
            return;
        }
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }

    void levelOrderTraversal(TreeNode* root, vector<int>& ans){
        int n = ans.size();
        for(int i = 0; i<n; i++){
            nthLevel(root, 0, i, ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        int ht = levels(root);
        vector<int>ans(ht);
        levelOrderTraversal(root, ans);
        return ans;
    }

*/


    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<int>& ans){
        if(root == NULL) return;
        nthLevel(root->left, curr + 1, level, ans);
        if(curr == level){
            ans[level] = root->val;
            return;
        }
        nthLevel(root->right, curr + 1, level, ans);
    }

    void levelOrderTraversal(TreeNode* root, vector<int>& ans){
        int n = ans.size();
        for(int i = 0; i<n; i++){
            nthLevel(root, 0, i, ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        int ht = levels(root);
        vector<int>ans(ht);
        levelOrderTraversal(root, ans);
        return ans;
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

    vector<int> res = rightSideView(a);
    for(int nums : res){
        cout<<nums<<" ";
    }
    
    cout << endl;
    return 0;
}
