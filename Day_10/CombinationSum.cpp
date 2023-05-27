#include<bits/stdc++.h>f
using namespace std;
/*
  Input: candidates = [2,3,6,7], target = 7
   Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/
void solve(int ind,vector<int>&arr,int k,vector<vector<int>>&ans,vector<int>&temp,int n){
    if(ind==n){
       if(k==0){
           ans.push_back(temp);
       }
       return;
    }
    if(arr[ind]<=k){
        temp.push_back(arr[ind]);
        solve(ind,arr,k-arr[ind],ans,temp,n); // Pick 
        temp.pop_back();
    }
    // Not pick
    solve(ind+1,arr,k,ans,temp,n);
}
vector<vector<int>> combinatinoSum(vector<int>&arr,int target){
     vector<vector<int>>ans;
      vector<int>temp;
      int n=arr.size();
      solve(0,arr,target,ans,temp,n);
      return ans;  
}