//Creating tree out of array via queue
#include<iostream>
#include<queue>
#include<vector>
#include<climits>

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

TreeNode* construct(vector<int> arr, int n){
	if(n == 0) return NULL;
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(arr[0]);
	q.push(root);
	int i = 1;
	while(q.size() > 0 && i<n){
		TreeNode* temp = q.front();
		q.pop();
		TreeNode *left = NULL;
		TreeNode *right = NULL;
		if(i != n && arr[i] != INT_MIN) left = new TreeNode(arr[i]);
		i++;
		if(i != n && arr[i] != INT_MIN) right = new TreeNode(arr[i]);
		i++;
		
		temp->left = left;
		temp->right = right;
		
		if(left != NULL) q.push(left);
		if(right != NULL) q.push(right);
	}
	return root;
}

void levelOrderQueue(TreeNode* root){
  if(root == NULL) return;
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
  vector<int>arr = {1, 2, 3, 4, 5, 6, 7};
  int n = arr.size();
  //construct
  TreeNode *root = construct(arr, n);
  levelOrderQueue(root);
}
