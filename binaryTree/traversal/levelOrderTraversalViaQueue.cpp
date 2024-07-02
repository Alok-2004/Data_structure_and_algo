//Level order Trversal using Queue (BFS)

#include<iostream>
#include<queue>
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

void levelOrderqueue(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  while(q.size()>0){
  	TreeNode* temp = q.front();
    q.pop();
    cout<<temp->val<<" ";
    if(temp->left != NULL) q.push(temp->left);
    if(temp->right != NULL) q.push(temp->right);
  }
//  cout<<endl;
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
  
  levelOrderqueue(a);
 
}
