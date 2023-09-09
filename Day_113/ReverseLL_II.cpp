#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int va;
    ListNode *next;
    ListNode(int va){
        val=v;
    }
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode *dummy=new ListNode();
      dummy->next=head;
      ListNode *temp=dummy;
      ListNode *ptr=head;
      for(int i=0;i<left-1;i++){
          temp=temp->next;
      }
      ListNode *p=temp->next;
     for(int j=0;j<right-left;j++){
        ListNode *t=p->next;
        p->next=t->next;
        t->next=temp->next;
        temp->next=t;
     }
     return dummy->next;
    }
};