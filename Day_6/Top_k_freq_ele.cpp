#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,1,1,2,2,3], k = 3
Output: [1,2]

Explanation:
  1 -> 3
  2 -> 2
  3 -> 1

  The Top K frequent Element is [1,2,3]

*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
       priority_queue<pair<int,int>>pq;
       for(auto it:mp){
           pq.push({it.second,it.first});
       }
       while(pq.size()>(int)mp.size()-k){
           int p=pq.top().second;
           ans.push_back(p);
           pq.pop();
       }
       return ans;
    }
};