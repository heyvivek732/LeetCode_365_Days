#include<bits/stdc++.h>
using namespace std;

// DP ,Hashing ,BinarySearch,Greedy
/*
Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
*/
class Solution {
public:
int solve(map<pair<int,int>,int>&dp,int prev,int ind,vector<int>&arr1,vector<int>&arr2){
    if(ind==arr1.size()) return 0;

    if(dp.find({ind,prev})!=dp.end()) return dp[{ind,prev}];

    int ans=INT_MAX/2;
    int id=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
    if(arr1[ind]>prev){
        ans=min(ans,solve(dp,arr1[ind],ind+1,arr1,arr2));
    }
    if(id<arr2.size()){
        ans=min(ans,solve(dp,arr2[id],ind+1,arr1,arr2)+1);
    }

    return dp[{ind,prev}]=ans;
}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
       map<pair<int,int>,int>dp;
       int ans=solve(dp,INT_MIN,0,arr1,arr2);
        return ans>=INT_MAX/2?-1:ans;
    }
};