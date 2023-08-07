#include<bits/stdc++.h>
using namespace std;
/*
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]


*/
// Optimal Approach  
    class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int>ans;
         stack<int>st;
         unordered_map<int,int>mp;
         int n=nums2.size();
         int temp=0;
         for(int i=n-1;i>=0;i--){
             temp=nums2[i];
             while(!st.empty() && st.top()<=temp)st.pop();
             if(st.empty())mp.insert({temp,-1});
             else mp.insert({temp,st.top()});

             st.push(temp);
         }
         for(auto it:nums1){
             ans.push_back(mp[it]);
         }
         return ans;
        }

    };

    // Brute Force Approach
        class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int>ans;
         int n=nums2.size();
         for(int i=0;i<nums1.size();i++){
             int temp=nums1[i];
             stack<int>st;
             st.push(-1);
             for(int j=n-1;j>=0;j--){
                 if(nums2[j]==temp)break;
                 if(nums2[j]>temp)st.push(nums2[j]);
                 
             }
           ans.push_back(st.top());
         }
         return ans;
        }

    };

