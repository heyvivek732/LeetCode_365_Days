#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool CanFormPairs(vector<int>&nums,int mid,int p){
      int cnt=0;
      for(int i=0;i<nums.size()-1 && cnt<p;i++){
          if(nums[i+1]-nums[i]<=mid){
              cnt++;
              i++;
          }
      }
      return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=nums[n-1]-nums[0];
        while(low<high){
            int mid=(low+high)>>1;
            if(CanFormPairs(nums,mid,p)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};