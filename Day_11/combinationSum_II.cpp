#include<bits/stdc++.h>
using namespace std;

/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/
void solve(int ind,vector<int>&arr,int k,vector<vector<int>>&ans,vector<int>&temp,int n){
        if(k==0){
             ans.push_back(temp);
             return;
         }
        else{
         for(int i=ind;i<arr.size();i++){
             if(arr[i]>k) return;
             if(i && arr[i]==arr[i-1] && i>ind) continue;
             temp.push_back(arr[i]);
             solve(i+1,arr,k-arr[i],ans,temp,n);
             temp.pop_back();
         }
        }
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        solve(0,candidates,target,ans,temp,n);
       return ans;
    }