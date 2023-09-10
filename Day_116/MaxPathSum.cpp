#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int v){
        val=v;
    }
};
int MaxPathSum(Node *root){
    int maxi=INT_MIN;
    solve(root,maxi);
    return maxi;
}
void solve(Node *root,int &maxi){
    if(root==NULL)return 0;

    int left=max(0,solve(root->left,maxi));
    int right=max(0,solve(root->right,maxi));

    maxi=max(maxi,left+right+root->val);

    return root->val+left+right;
}