#include<bits/stdc++.h>
using namespace std;

/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        string str="";
       for(int i=0;i<nums.size();i++){
              int j=i;
              while(j+1<nums.size() && nums[j]+1==nums[j+1]){
                  j++;
              }
              if(j>i){
              str=to_string(nums[i])+"->"+to_string(nums[j]);
              }else{
               str=to_string(nums[i]);
              }
              ans.push_back(str);
              i=j;
              str="";
       }
       return ans;
    }
};