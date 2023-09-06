#include<bits/stdc++.h>
using namespace std;
/*
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v){
        val=v;
    }
}
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int extraNode=cnt%k;
        int numOfSplit=cnt/k;
        temp=head;
        while(temp!=NULL){
            ans.push_back(temp);
            int curr=1;
            while(curr<numOfSplit){
                temp=temp->next;
                curr++;
            }
            if(extraNode >0 && cnt>k){
                temp=temp->next;
                extraNode--;
            }
            ListNode *ptr=temp->next;
            temp->next=NULL;
            temp=ptr;
         }
        while(cnt<k){
            ans.push_back(NULL);
            cnt++;
        }
        return ans;
    }
};