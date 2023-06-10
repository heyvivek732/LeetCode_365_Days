#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/

//Binary Search

int splitArray(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        
        int sum=0;
        for(auto it:nums)sum+=it;
        
        int low=maxi,high=sum,ans=0;
        while(low<=high){
            int cnt=1,curr=0;
            int mid=(low+high)>>1;
            for(int i=0;i<nums.size();i++){
                curr+=nums[i];
                if(curr>mid){
                    cnt++;
                    curr=nums[i];
                }
            }
            if(cnt>k){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }