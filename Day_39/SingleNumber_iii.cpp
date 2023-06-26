#include<bits/stdc++.h>
using namespace std;

// Single Number

/*
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Each integer in nums will appear twice, only two integers will appear once.
*/
  vector<int> singleNumber(vector<int>& nums) {
        unordered_map<long long,int>mp;
        vector<int>ans(2);
        for(auto it:nums)mp[nums[it]]++;
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }