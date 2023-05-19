#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        val=0;
        next=nullptr;
    }
    ListNode(int val){
        val=val;
        next=nullptr;
    }
};
 ListNode* mergeNodes(ListNode* head) {
        ListNode *temp=head;
        ListNode *p=head->next;
        while(p!=NULL){
            if(p->val!=0){
                temp->val+=p->val;
            }else{
                temp->next=(p->next)!=nullptr?p:nullptr;
                temp=p;
            }
            p=p->next;
        }
        return head;
    }