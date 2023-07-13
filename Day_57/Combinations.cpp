#include<bits/stdc++.h>
using namespace std;


/*
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
*/
void solve(int ind,int n,int k,vector<vector<int>>&ans,vector<int>&temp){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<=n;i++){
        temp.push_back(i);
        solve(i+1,n,k,ans,temp);
        temp.pop_back();
    }
}
vector<vector<int>> Combinations(int n,int k){
    vector<vector<int>>ans;
    vector<int>temp;
    solve(1,n,k,ans,temp);
    return ans;
}