#include<bits/stdc++.h>
using namespace std;
//Recusion
int solve(int left,int right,vector<int>&cuts,int left_cut,int right_cut){
    if(left_cut>right_cut) return 0; 
    int cost=1e9;
    for(int i=left_cut;i<=right_cut;i++){
        int left_cost=solve(left,cuts[i],cuts,left_cut,i-1);

        int right_cost=solve(cuts[i],right,cuts,i+1,right_cut);

        int curr=(right-left)+right_cost+left_cost;
        
        cost=min(cost,curr);
    }
    return cost;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        return solve(0,n,cuts,0,cuts.size()-1);
}
// Memoization With Dp


int dp[101][101];
int solve(int left,int right,vector<int>&cuts,int left_cut,int right_cut){
    if(left_cut>right_cut) return 0; 

    if(dp[left_cut][right_cut]!=-1) return dp[left_cut][right_cut];
    int cost=1e9;
    for(int i=left_cut;i<=right_cut;i++){
        int left_cost=solve(left,cuts[i],cuts,left_cut,i-1);

        int right_cost=solve(cuts[i],right,cuts,i+1,right_cut);

        int curr=(right-left)+right_cost+left_cost;
        
        cost=min(cost,curr);
    }
    return dp[left_cut][right_cut]=cost;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,n,cuts,0,cuts.size()-1);
}