#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
       queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
           for(int i=0;i<sz;i++){
               TreeNode *temp=q.front();
               q.pop();

               if(i==sz-1)ans.push_back(temp->val);

               if(temp->left)q.push(temp->left);
               if(temp->right)q.push(temp->right); 
           }
        }
        return ans;
    }
};