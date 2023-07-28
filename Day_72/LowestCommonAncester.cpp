#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            Node *temp=root;
            while(temp){
                 if(temp->data==n1 || temp->data==n2)return temp;
                 if(temp->data<n1 && temp->data<n2)temp=temp->right;
                 else if(temp->data>n1 && temp->data>n2)temp=temp->left;
                 else if(temp->data<n1 && temp->data>n2)return temp;
                 else if(temp->data>n1 && temp->data<n2)return temp;
            }
        }

};