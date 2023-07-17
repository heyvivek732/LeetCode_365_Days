#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
ListNode *reverse(ListNode *head){
    ListNode *prev=NULL;
    while(head!=NULL){
        ListNode *temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *dummy=new ListNode();
      ListNode *temp=dummy;
     int carry=0;
     ListNode *t1=reverse(l1);
     ListNode *t2=reverse(l2);
    while(t1!=NULL || t2!=NULL || carry){
        int sum=0;
       if(t1!=NULL){
           sum+=t1->val;
           t1=t1->next;
       }
       if(t2!=NULL){
           sum+=t2->val;
           t2=t2->next;
       }
     sum+=carry;
     carry=sum/10;
     ListNode *node=new ListNode(sum%10);
     temp->next=node;
     temp=temp->next;
    }
    ListNode *ans=reverse(dummy->next);
    return ans;
    }
};