#include<bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// BruteForce Approach
 vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       vector<int>ans(n,1); 
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(i==j)continue;
               ans[i]=ans[i]*nums[j];
           }
       } 
       return ans;
}

// Intuition 
/*
1st ->  calculate prefix Product without including nums[i]
2nd -> calculate suffix product without including nums[i]
3rd -> calculate prefic * suffix product we get ans
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       vector<int>ans(n,1); 
       vector<int>prefix(n);
       vector<int>suffix(n);
       prefix[0]=1;
       for(int i=1;i<n;i++){
           prefix[i]=prefix[i-1]*nums[i-1];
       }
       suffix[n-1]=1;
       for(int i=n-2;i>=0;i--){
           suffix[i]=suffix[i+1]*nums[i+1];
       }
       for(int k=0;k<n;k++){
           ans[k]=prefix[k]*suffix[k];
       }
       return ans;
    }
};