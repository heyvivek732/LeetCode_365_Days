#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int v){
        val=v;
        next=NULL;
    }
};
int getlength(Node *head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
    Node* reverseKGroup(Node* head, int k) {
        if(!head && !head->next) return head;

        Node *dummy=new Node(0);
        dummy->next=head;
        Node *curr=dummy,*prev=dummy,*nex=dummy;

        int len=getlength(head);
        while(len>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            len-=k;
        }
        return dummy->next;
    }