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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,multiset<int>>>mp;

       queue<pair<TreeNode*,pair<int,int>>>q;

       q.push({root,{0,0}});
       while(!q.empty()){
           auto frnt=q.front();
           q.pop();
           TreeNode *temp=frnt.first;
           int x=frnt.second.first,y=frnt.second.second;
           mp[x][y].insert(temp->val);
           if(temp->left)q.push({temp->left,{x-1,y+1}});
           if(temp->right)q.push({temp->right,{x+1,y+1}});
       }

       vector<vector<int>>ans;

       for(auto it:mp){
           vector<int>temp;
           for(auto j:it.second){
               temp.insert(temp.end(),j.second.begin(),j.second.end());
           }
           ans.push_back(temp);
       }
       return ans;
    }
};