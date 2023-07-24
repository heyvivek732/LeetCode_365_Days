#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int sz=q.size();
           while(sz--){
               Node *temp=q.front();
               q.pop();
               if(sz==0)ans.push_back(temp->data);
           if(temp->left)q.push(temp->left);
           if(temp->right)q.push(temp->right);
           }
       }
       return ans;
    }
};