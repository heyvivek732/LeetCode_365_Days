#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       stack<int>s1,s2;
       int n=arr.size();
       long long mod=1e9+7;
       vector<long>prev_smll(n);
       vector<long>nxt_smll(n);
       for(int i=0;i<n;i++){
           nxt_smll[i]=n-i-1;
           prev_smll[i]=i;
       }  

       for(int i=0;i<n;i++){
           while(!s1.empty() && arr[s1.top()]>arr[i]){
               nxt_smll[s1.top()]=i-s1.top()-1;
               s1.pop();
           }
           s1.push(i);
       } 
      
       for(int i=n-1;i>=0;i--){
           while(!s2.empty() && arr[s2.top()]>=arr[i]){
               prev_smll[s2.top()]=s2.top()-i-1;
               s2.pop();
           }
           s2.push(i);
       }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(arr[i]*((prev_smll[i]+1)*(nxt_smll[i]+1)));
        ans%=mod;
    }
    return ans;
    }
};