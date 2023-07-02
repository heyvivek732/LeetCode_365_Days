#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{ 
public:
Node *getMid(Node *head){
        Node *slow=head;
        Node *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}
Node *reverse(Node *head){
    Node *prev=NULL;
    while(head!=NULL){
        Node *temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}
void mergeTwoList(Node *l1,Node *l2){
   while(l1!=NULL && l2!=NULL){
       Node *p=l1->next;
       Node *p1=l2->next;
       
       l1->next=l2;
       l2->next=p;
       
       l1=p;
       l2=p1;
   }
    
}
  void reorderList(Node* head) {
       if(!head || !head->next) return;
        
        Node *mid=getMid(head);
        Node *half=mid->next;
        mid->next=NULL;
        
        half=reverse(half);
        
        mergeTwoList(head,half);
    }
};