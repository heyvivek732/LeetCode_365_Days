#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int v){
        val=v;
    }
};
class Solution {
public:
bool isValid(TreeNode *root,TreeNode *root1){
    if(!root && !root1)return true;
    if(!root || !root1 )return false;

    if(root->val!=root1->val)return false;

    bool left=isValid(root->left,root1->left);
    bool right=isValid(root->right,root1->right);

    return left && right;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(!root)return false;
      
      bool check=isValid(root,subRoot);

      if(check)return true;

      bool left =isSubtree(root->left,subRoot);
      bool right=isSubtree(root->right,subRoot);

      return left || right;
    }
};
