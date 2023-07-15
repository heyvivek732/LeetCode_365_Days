#include<bits/stdc++.h>
using namespace std;

/*
Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
*/
class Solution {
public:
int Search(int ind,vector<vector<int>>&events,int val){
    int  low=ind,high=events.size()-1,req=-1;
    while(high>=low){
        int mid=(low+high)>>1;
        if(events[mid][0]>val){
            req=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return req;
}
int solve(int ind,vector<vector<int>>&events,int  k,vector<vector<int>>&dp){
    if(ind>=events.size() || k==0 || ind==-1)return 0;
    if(dp[ind][k]!=-1)return dp[ind][k];

    int index=Search(ind+1,events,events[ind][1]);
    
    int val1=events[ind][2]+solve(index,events,k-1,dp);
    int val2=solve(ind+1,events,k,dp);

    return dp[ind][k]=max(val1,val2);
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>>dp(n+5,vector<int>(k+1,-1));
        return solve(0,events,k,dp);
    }
};