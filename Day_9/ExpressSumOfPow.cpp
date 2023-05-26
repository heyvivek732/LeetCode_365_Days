#include<bits/stdc++.h>
using namespace std;
/*
GfG Problem of The Day
Input: 
n = 10, x = 2
Output: 
1 
Explanation: 
10 = 12 + 32, Hence total 1 possibility. 

Input: 
n = 100, x = 2
Output: 
3
Explanation: 
100 = 102 
62 + 82 and 12 + 32 + 42 + 52 + 72 
Hence total 3 possibilities. 
*/

//Solving By The Recursion Memoization with dp;
int mod=1000000007;
    int solve(int ind,int n,int x,vector<vector<int>>&dp){
        if(ind>n){
            if(n==0) return 1;
            return 0;
        }
        if(dp[ind][n]!=-1) return dp[ind][n];
        int pick=0;
        if(n>0){
            pick=solve(ind+1,n-(int)pow(ind,x),x,dp);
        }
        int notpick=solve(ind+1,n,x,dp);
        return dp[ind][n]=(pick+notpick)%mod;
    }
    int numOfWays(int n, int x)
    {
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       
       return solve(1,n,x,dp);
    }