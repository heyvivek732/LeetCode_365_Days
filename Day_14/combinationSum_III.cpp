#include<bits/stdc++.h>
using namespace std;
/*
Conditions : Only numbers 1 through 9 are used.
            Each number is used at most once. 


Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
*/
class Solution {
public:
void solve(int ind,int sum,int currSm,vector<vector<int>>&ans,vector<int>&temp,int k){
    if(k<temp.size() || currSm>sum){
        return;
    }
    if(currSm==sum && k==temp.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<=9;i++){
       currSm+=i;
       temp.push_back(i);
       solve(i+1,sum,currSm,ans,temp,k);
       currSm-=i;
       temp.pop_back();
    }   
}
    vector<vector<int>> combinationSum3(int k, int sum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int currSm=0;
        solve(1,sum,currSm,ans,temp,k);
        return ans;
    }
};