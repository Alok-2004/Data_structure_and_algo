//level Order Traversal via DFS(farzi tarika)
#include<iostream>

using namespace std;

class TreeNode{
  public:
  	long long val;
  	TreeNode *left;
  	TreeNode *right;
  	
  	TreeNode(long long val){
  		this->val = val;
  		this->left = NULL;
  		this->right = NULL;
	  }
};
/*
void print(TreeNode* root,int check, int level){
  if(root == NULL) return;
  if(check == level){
    cout<<root->val<<" ";
    return;
  }
  print(root->left, check+1, level);
  print(root->right, check + 1, level);
}


int level(TreeNode* root){
  if(root == NULL) return 0;
  return 1 + max(level(root->left) , level(root->right));
}
*/

//using bfs

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int level = q.size();
        vector<int>helper;
        for(int i = 0; i<level; i++){
            TreeNode* temp = q.front();
            q.pop();
            helper.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(helper);
    }
    return ans; 
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
  
  int levels = level(a);
  for(int i = 1 ; i<=levels; i++){
	print(a, 1, i); 
	cout<<endl;
  }
 
}

