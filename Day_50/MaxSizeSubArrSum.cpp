#include<bits/stdc++.h>
using namespace std;
/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int temp=0;
        int j=0,i=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j++];
            while(sum>=target){
                len=min(len,j-i);
                sum-=nums[i++];
            }
        }
        return len==INT_MAX?0:len;
    }
};