#include<bits/stdc++.h>
using namespace std;
// Leetcode 468 Predicst Winner
class Solution {
public:
int solve(int p1,int p2,int i,int j,bool turn,vector<int>&nums){
    if(i>j){
        if(p1>=p2)return 1;

        return 0;
    }
   if(turn)return solve(p1+nums[i],p2,i+1,j,false,nums)||solve(p1+nums[j],p2,i,j-1,false,nums);
   else return solve(p1,p2+nums[i],i+1,j,true,nums) && solve(p1,p2+nums[j],i,j-1,true,nums);
}
    bool PredictTheWinner(vector<int>& nums) {
        int p1=0,p2=0,i=0,j=nums.size()-1;
       return solve(p1,p2,i,j,true,nums);
    }
};