#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int val){
        val=val;
        left=nullptr;
        right=nullptr;
    }
};

/*
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
*/
int Max_Sum_level(Node *root){
    if(!root) return 0;
    queue<Node*>q;
    q.push(root);

    int curr_sum=0,level=0,mx=INT_MIN,curr_leve=0;
    while(!q.empty()){
        int n=q.size();
        int sum=0;
        ++level;
        while(n>0){
            Node *temp=q.front();
            q.pop();
            sum+=temp->val;

            if(temp->left) q.push(root->left);
            if(temp->right) q.push(root->right);

            n--;
        }
        if(sum>mx){
            mx=sum;
            curr_leve=level;
        }
    }
    return level;
}
int main(){
    Node *root;
    root->val=10;
    root->left->val=20;
    root->right->val=30;
    root->left->left->val=40;
    root->left->right->val=33;
    root->right->left->val=44;
    root->right->right->val=32;

    cout<<"the Maxi Sum Level is : "<<Max_Sum_level(root);
}