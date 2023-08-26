#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is 
*/
int maxConsecutiveOne(vector<int>&nums,int k){
       int i=0,j=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt++;
            }
            if(cnt>k){
                if(nums[i]==0)cnt--;
                i++;
            }
            j++;
        }
        return j-i;
}