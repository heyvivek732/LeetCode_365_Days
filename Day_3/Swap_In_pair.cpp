#include<bits/stdc++.h>
using namespace  std;
struct Node {
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

class Solution {
public:
    Node* swapPairs(Node* head) {
     if(!head || !head->next) return head;
     Node *temp=head;
     int k=2;
     int cnt=0;
     while(temp!=NULL){
       cnt++;
       temp=temp->next;
     }
     
    Node *dummy=new Node(0);
    dummy->next=head;

    Node *curr=dummy,*prev=dummy,*nxt=dummy;

    while(cnt>=k){
        curr=prev->next;
         nxt=curr->next;
        for(int i=1;i<k;i++){
           curr->next=nxt->next;
           nxt->next=prev->next;
           prev->next=nxt;
           nxt=curr->next;
        }
        prev=curr;
        cnt-=k;
    }
    return dummy->next;
    }
};