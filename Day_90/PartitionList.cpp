#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int d){
        val=d;
        next=NULL;
    }
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy=new ListNode(-1);
        ListNode *dummy_head=dummy;
        ListNode *curr=head;
        ListNode *dummy1=new ListNode(-1);
        ListNode *dummy1_head=dummy1;
        while(curr!=NULL){
            if(curr->val<x){
               dummy_head->next =new ListNode(curr->val);
               dummy_head=dummy_head->next;
            }else{
                dummy1_head->next = new ListNode(curr->val);
                dummy1_head=dummy1_head->next;
            }
            curr=curr->next;
        }
        dummy_head->next=dummy1->next;
        dummy1_head->next=NULL;
       return dummy->next;
    }
};