#include<bits/stdc++.h>
using namespace std;
/*
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.
*/
class Solution {
public:
int ans=0;
int check(int ind,string &s,unordered_map<string,int>&mp,vector<int>&dp){
    if(ind==s.size())return 0;
    if(dp[ind]!=-1)return dp[ind];
    
    string temp="";
    int ans=s.size();
    for(int i=ind;i<s.size();i++){
       temp.push_back(s[i]);

       int a=(mp.count(temp))?0:temp.size();
       int next=check(i+1,s,mp,dp);
       int total=a+next;
       ans=min(ans,total);
    }
    return dp[ind]=ans;
}
    int minExtraChar(string s, vector<string>& str) {
      unordered_map<string,int>mp;
      vector<int>dp(s.size(),-1);
      for(auto it:str)mp[it]++;
     return check(0,s,mp,dp);
     
    }
};