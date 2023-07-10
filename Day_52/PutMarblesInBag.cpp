#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

// We can Make Pair of Its Weights[i]+Weights[i+1]
// [1,3,5,1] ,k=2  => (1 | 3 5 1) , (1 3 | 5 1) ,(1 3 5 | 1)

/* I can Simply Make Pair with its neighbours ,Because We Make Partition anywhere In the Weights, So we Think With Greedy Approach We Make its neighbours Sum 

1st Approach : -> 
  We Make an Extra Arr to store (weights[i] and Weights[i+1]) sum and Then We Can  Sort them.
  Now, We Simply go k-1 from begining and add to minimum and go last and add k-1 element into the Maximum 
  Simply return maximum-minimum 
 TC: nlog(n) ->sorting
 SC:(N)  -> store the sum


2nd Approach : ->
  
*/
    long long putMarbles(vector<int>& weights, int k) {
       int n=weights.size();
       long long maxi=0,mini=0;
       
       priority_queue<int>pq1;
       priority_queue<int,vector<int>,greater<int>>pq2;
       for(int i=0;i<n-1;i++){
           pq1.push(weights[i]+weights[i+1]);
           if(pq1.size()==k){
               pq1.pop();
           }
           pq2.push(weights[i]+weights[i+1]);
           if(pq2.size()==k){
               pq2.pop();
           }
       }
       long long ans=0;
      while(!pq2.empty()){
         ans+=pq2.top()-pq1.top();
         pq1.pop();
         pq2.pop();
      }
       return ans;
    }
};