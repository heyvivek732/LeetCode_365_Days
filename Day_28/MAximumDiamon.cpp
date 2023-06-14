#include<bits/stdc++.h>
using namespace std;
/*
There are N bags with diamonds in them. The i'th of these bags contains A[i] diamonds. If you drop a bag with A[i] diamonds, it changes to A[i]/2 diamonds and you gain A[i] diamonds. Dropping a bag takes 1 minute. Find the maximum number of diamonds that you can take if you are given K minutes.

Input:
N = 5, K = 3
A[] = {2, 1, 7, 4, 2}
Output:
14
Explanation:
The state of bags is:
2 1 7 4 2
You take all diamonds from Third bag (7).
The state of bags becomes: 2 1 3 4 2 
Take all diamonds from Fourth bag (4).
The state of bags becomes: 2 1 3 2 2
Take all diamonds from Third bag (3).
The state of bags becomes: 2 1 1 2 2 
Hence, number of Diamonds = 7+4+3 = 14.

*/
long long maxDiamonds(int arr[], int n, int k) {
        priority_queue<int>pq;
        for(int i=0;i<n;i++)pq.push(arr[i]);
        long long ans=0;
        int cnt=0;
        while(pq.size()>0){
            int temp=pq.top();
            ans+=temp;
            temp=temp>>1;
            pq.pop();
            cnt++;
            pq.push(temp);
            if(cnt==k){
                break;
            }
        }
        return ans;
    }