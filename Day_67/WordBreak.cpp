#include<bits/stdc++.h>
using namespace std;

/*
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
*/
class Solution {
public:
bool check(int ind,string s,unordered_set<string>&st,vector<int>&prev){
    if(ind==s.size())return true;
    if(prev[ind]!=-1)return prev[ind];
    for(int i=ind;i<s.size();i++){
        if(st.count(s.substr(ind,i+1-ind)) &&  check(i+1,s,st,prev)){
           prev[ind]=true;
           return true;
        }
    }
    return prev[ind]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>prev(s.size(),-1);
       unordered_set<string>st(begin(wordDict),end(wordDict));
      return check(0,s,st,prev);
    }
};