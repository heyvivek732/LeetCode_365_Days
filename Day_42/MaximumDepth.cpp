#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        if(!root) return 0;
        
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }
    }
};