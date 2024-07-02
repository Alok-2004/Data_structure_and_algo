// Depth First Search using stack
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

vector<int> preOrderIterative(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        cout << temp->val << " ";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
    cout << endl;
    return ans;
}

vector<int> postOrderIterative(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        cout << temp->val << " ";
        if (temp->left) st.push(temp->left);
        if (temp->right) st.push(temp->right);
    }
    cout << endl;
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> inOrderIterative(TreeNode* root){
	vector<int> ans;
	if(root == NULL) return ans;
	stack<TreeNode*> st;
	TreeNode* node = root;
	while(!st.empty() || node){
		if(node){
			st.push(node);
			node = node->left;
		}else{
			TreeNode* temp = st.top();
			st.pop();
			cout<<temp->val<<" ";
			ans.push_back(temp->val);
			node = temp->right;
		}
	}
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
    
    cout << "Pre Order" << endl;
    vector<int> ans1 = preOrderIterative(a);
    
    cout << "Post Order" << endl;
    vector<int> ans2 = postOrderIterative(a);
    
    cout << "In Order" << endl;
    vector<int> ans3 = inOrderIterative(a);
    return 0;
}

