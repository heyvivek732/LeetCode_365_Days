#include<bits/stdc++.h>
using namespace std;
/*
Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
*/
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        Node *dummy=new Node(0);
        Node *temp=dummy;
        set<int>st;
        while(head1!=NULL){
            st.insert(head1->data);
            head1=head1->next;
        }
        while(head2!=NULL){
            st.insert(head2->data);
            head2=head2->next;
        }
        for(int it:st){
            temp->next=new Node(it);
            temp=temp->next;
        }
        return dummy->next;
    }