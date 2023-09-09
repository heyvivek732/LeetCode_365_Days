#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int v){
        val=v;
    }
};
class Solution {
public:
int solve(vector<int>&nums,int target,int sum,vector<int>&dp){
   if(sum>target)return 0;
   if(target==sum)return 1;
   if(dp[sum]!=-1)return dp[sum];
    int cnt=0;
    for(auto it:nums){
        cnt+=solve(nums,target,sum+it,dp);
    }
    return dp[sum]=cnt;
}
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size()==0)return 0;
        vector<int>dp(target+1,-1);
        return solve(nums,target,0,dp);
    }
};