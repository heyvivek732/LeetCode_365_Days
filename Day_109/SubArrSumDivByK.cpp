#include<bits/stdc++.h>
using namespace std;
/*
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            if(sum<0)sum+=k;
            cnt+=mp[sum];
            mp[sum]++;
        }
        return cnt;
    }
};