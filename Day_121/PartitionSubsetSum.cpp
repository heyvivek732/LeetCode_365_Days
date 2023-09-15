#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   bool solve(int ind,vector<int>&nums,int sum,vector<vector<int>>&dp){
       if(sum==0)return true;

       if(ind<0 || sum<0)return false;

       if(dp[ind][sum]!=-1)return dp[ind][sum];

       int pick=solve(ind-1,nums,sum-nums[ind],dp);
       int not_pick=solve(ind-1,nums,sum,dp);

       return dp[ind][sum]=pick | not_pick;
   }
    bool canPartition(vector<int>& nums) {
      int sum=accumulate(nums.begin(),nums.end(),0);
      if(sum%2!=0)return false;
      sum/=2;
      vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
      return solve(nums.size()-1,nums,sum,dp); 
    }
};