#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> helper(TreeNode* root, int level, unordered_map<int, int>& m, vector<int>& res) {
    queue<pair<TreeNode*, int>> q; // int -> level
    q.push({root, level});
    int minLevel = INT_MAX, maxLevel = INT_MIN;
    while (!q.empty()) {
        TreeNode* temp = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if (m.find(lvl) == m.end())  m[lvl] = temp->val;
        if (temp->left)  q.push({temp->left, lvl - 1});
        
        if (temp->right)  q.push({temp->right, lvl + 1});
    }
    for(auto ele : m){
        int level = ele.first;
        minLevel = min(minLevel, level);
        maxLevel = max(maxLevel, level);
    }
    for(int i = minLevel; i<=maxLevel; i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
    
    for(const auto& pair : m) 
        res.push_back(pair.second);

    sort(res.begin(), res.end());

    return res;
}

vector<int> topView(TreeNode* root) {
    unordered_map<int, int> m; // int -> flag, int -> val
    vector<int> res;
    if (root == NULL) return res;
    res = helper(root, 0, m, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<int> result = topView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
