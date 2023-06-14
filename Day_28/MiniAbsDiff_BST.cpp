#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left,*right;

    TreeNode(int val){
        val=val;
    }
};

class Solution {
public:
int InOrder(TreeNode* root,int& mini,int& val){
    if(root->left!=nullptr) InOrder(root->left,mini,val);
    if(val>=0) mini=min(mini,root->val-val);
    val=root->val;
    if(root->right!=NULL) InOrder(root->right,mini,val);
    return mini;
}
    int getMinimumDifference(TreeNode* root) {
       int mini=INT_MAX,val=-1;
       return InOrder(root,mini,val);
    }
};