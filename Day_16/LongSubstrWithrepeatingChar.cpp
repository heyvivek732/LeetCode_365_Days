#include<bits/stdc++.h>
using namespace std;
/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
// Better Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      set<char>st;
       int i=0,j=0;
       int mx=0;
       while(j<s.size()){
           if(st.find(s[j])==st.end()){
               st.insert(s[j++]);
               int n=st.size();
               mx=max(mx,n);
           }else{
               st.erase(s[i++]);
           }
       }
      return mx;
    }
};

// Most Optimal Approaches
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>ans(256,-1);
       int i=-1,j=0;
       int mx=0;
       for(int j=0;j<s.size();j++){
           if(ans[s[j]]>i){
               i=ans[s[j]];

           }
           ans[s[j]]=j;
           mx=max(mx,j-i);
       }
      return mx;
    }
};