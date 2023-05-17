#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node(int val){
        val=val;
        next=nullptr;
    }
};
Node *reverse(Node *head){
    Node *prev=nullptr;
    while(head!=NULL){
        Node *temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}
Node *middle(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
    int pairSum(Node* head) {
        if(!head || !head->next) return 0;
       Node *mid=middle(head);
       Node *rev=reverse(mid->next);

       int mx=0;
       while(rev!=nullptr){
           int ans=head->val+rev->val;
           if(ans>mx){
               mx=ans;
           }
           rev=rev->next;
           head=head->next;
       }
       return mx;
    }