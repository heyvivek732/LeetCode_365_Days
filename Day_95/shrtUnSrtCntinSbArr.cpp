#include<bits/stdc++.h>
using namespace std;
/*
Keep Track Of Previous Element,
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int k=-1;
        int temp=nums[0];
        for(int i=1;i<n;i++){
            if(temp>nums[i])k=i;
            else temp=nums[i];
        }
        int j=0;
        temp=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(temp<nums[i])j=i;
            else temp=nums[i];
        }
        return k-j+1;
    }
};