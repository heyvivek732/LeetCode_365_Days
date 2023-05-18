#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next,*random;
    Node(int data){
        val=data;
        next=nullptr;
        random=nullptr;
    }
};
// Brute Force Using Map
// TC:O(N)+O(N)
// SC:O(N)
 Node *copyList(Node *head)
    {
        unordered_map<Node*,Node*>mp;
        Node *temp=head;
        while(temp!=NULL){
            Node *newNode=new Node(temp->val);
            mp[temp]=newNode;
            temp=temp->next;
        }
        Node *t=head;
        while(t!=NULL){
            Node *node=mp[t];
            node->next=(t->next!=nullptr)?mp[t->next]:NULL;
            node->random=(t->random!=nullptr)?mp[t->random]:NULL;
            t=t->next;
        }
        return mp[head];
 }
 // Optimal Approach
//TC:O(N)+O(N)+O(N)
//SC:O(1)
Node* copyRandomList(Node* head) {
      Node *temp=head;
      while(temp!=NULL){
          Node *newNode=new Node(temp->val);
          newNode->next=temp->next;
          temp->next=newNode;
          temp=temp->next->next;
      }     
      Node *itr=head;
      while(itr!=NULL){
          if(itr->random!=NULL){
              itr->next->random=itr->random->next;
          }
          itr=itr->next->next;
      }
      Node *dummy=new Node(0);
       itr=head;
      temp=dummy;
      Node *fast;
      while(itr!=NULL){
          fast=itr->next->next;
          temp->next=itr->next;
          itr->next=fast;
          temp=temp->next;
          itr=fast;
      }
      return dummy->next;
    }
