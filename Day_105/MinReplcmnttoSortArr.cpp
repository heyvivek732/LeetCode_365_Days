#include<bits/stdc++.h>
using namespace std;
/*
You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.

For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
Return the minimum number of operations to make an array that is sorted in non-decreasing order.

 
*/
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
       long long oper=0;
       int n=nums.size();
       long long rem;
       int last=nums[n-1];
      for(int i=n-2;i>=0;i--){
           if(last>=nums[i]){
             last=nums[i];
           }else{
              rem=(nums[i]-1)/(last)+1;
              last=nums[i]/rem;
               oper+=(rem-1);
           }
      }
      return oper;
    }
};