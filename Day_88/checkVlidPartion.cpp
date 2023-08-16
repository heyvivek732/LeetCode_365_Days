#include<bits/stdc++.h>
using namespace std;
/*
Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
*/
class Solution {
public:
bool solve(int i,vector<int>&nums,int n,vector<int>&dp){
    if(i>=n)return true;

   if(dp[i]!=-1)return dp[i];

    if(i+1<n && nums[i]==nums[i+1]){
         dp[i]=solve(i+2,nums,n,dp);
         if(dp[i])return true;

        if(i+2<n && nums[i]==nums[i+2]){
          dp[i]=solve(i+3,nums,n,dp);
          if(dp[i])return true;
       }
    }
    if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i]==2){
        dp[i]=solve(i+3,nums,n,dp);
        if(dp[i])return true;
    }
    return false;
  

}
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,nums.size(),dp);
    }
};