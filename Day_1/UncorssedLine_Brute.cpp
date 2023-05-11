#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int i,int j,vector<int>&nums1,vector<int>nums2){
     if(i==nums1.size() || j==nums2.size()) return 0;

    int cnt=0;
    if(nums1[i]==nums2[j]){
        cnt=1+solve(i+1,j+1,nums1,nums2);
    }else{
        cnt+=max(solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2));
    }
    return cnt;
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return solve(0,0,nums1,nums2);
    }
};