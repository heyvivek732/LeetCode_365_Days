#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node *left,*right;
    Node(){
        left=nullptr;
        right=nullptr;
        val=0;
    }
    Node(int v){
        val=v;
        left=nullptr;
        right=nullptr;
    }
};
Node *contructFullBinaryTree(int pre[],int pre_mirror[],int size){
    int ps=0,pe=size-1,pms=0,pme=size-1;
    return solve(ps,pe,pre,pms,pme,pre_mirror);
}
Node* solve(int ps,int pe,int pre[],int pms,int pme,int pre_mirror[]){
    if(ps>pe || pms>pme) return  nullptr;

    Node *newNode=new Node(pre[ps]);
    if(ps==pe) return newNode;
    int i,j;
    for( i=ps;i<=pe;++i){
        if(pre[i]==pre_mirror[pms+1]) break;
    }
    for(j=pms;j<=pme;++j){
        if(pre_mirror[j]==pre[ps+1]) break;
    }

    newNode->left=solve(ps+1,i-1,pre,pms,pme,pre_mirror);
    newNode->right=solve(ps,pe,pre,pms+1,j-1,pre_mirror);
    return newNode;
}
int main(){
    Node *root=nullptr;
    int pre[7]={1,2,4,5,3,6,7};
    int pre_mirror[7]={1,3,7,6,2,5,4};
    contructFullBinaryTree(pre,pre_mirror,7);
}