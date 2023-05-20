#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  /*
  Input: head = [1,2,3,3,4,4,5]
  Output: [1,2,5]
  */
  ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        
        while(head!=NULL){
            if(head->next!=nullptr && head->val==head->next->val){
                while(head->next!=nullptr && head->val==head->next->val){
                   head=head->next;
                }
                prev->next=head->next;
            }else{
                prev=prev->next;
            }
            head=head->next;
        }
        return dummy->next;
}