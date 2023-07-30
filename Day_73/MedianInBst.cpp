#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
void InOrder(Node *root,vector<int>&vis){
    if(root==NULL)return;
    InOrder(root->left,vis);
    vis.push_back(root->data);
    InOrder(root->right,vis);
}
float findMedian(struct Node *root)
{
    vector<int>vis;
    InOrder(root,vis);
    int n=vis.size();
    int n1=n>>1;
    int n2=(n-1)>>1;
    return (float)(vis[n1]+vis[n2])/2;
}
