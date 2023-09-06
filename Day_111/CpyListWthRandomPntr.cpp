#include<bits/stdc++.h>
using namespace std;
class Node {
    int val;
    Node *next;
    Node *random;
    Node(int v){
        val=v;
    }
};
// Approache And Optimal 
class Solution {
public:
    Node* copyRandomList(Node* head) {
      Node *temp=head;
      while(temp!=NULL){
          Node *newNode=new Node(temp->val);
         newNode->next=temp->next;
         temp->next=newNode;
         temp=temp->next->next;
      }

      Node *ptr=head;
      while(ptr!=NULL){
          if(ptr->random!=NULL)
          ptr->next->random=ptr->random->next;
          ptr=ptr->next->next;
      }

      Node *dummy =new Node(0);
      temp=dummy;
      ptr=head;
      Node *fast;
      while(ptr!=NULL){
          fast=ptr->next->next;
          temp->next=ptr->next;
         ptr->next=fast;
         temp=temp->next;
         ptr=fast;
      }
      return dummy->next;
    }

};
// Approach II Brute Force
class Solution {
public:
    Node* copyRandomList(Node* head) {
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
         node->next=(t->next!=NULL)?mp[t->next]:NULL;
         node->random=(t->random!=NULL)?mp[t->random]:NULL;
         t=t->next;
     }
     return mp[head];
    }

};