#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void solve(int ind,string& str,string& temp,vector<string>&ans,unordered_map<char,string>&mp){
    if(str.size()==0){
        return;
    }
    if(ind==str.size()){
        ans.push_back(temp);
        return;
    }
    string s=mp[str[ind]];
    for(int i=0;i<s.size();i++){
        temp.push_back(s[i]);
        solve(ind+1,str,temp,ans,mp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
      unordered_map<char,string>mp;
      mp['2']="abc";
      mp['3']="def";
      mp['4']="ghi";
      mp['5']="jkl";
      mp['6']="mno";
      mp['7']="pqrs";
      mp['8']="tuv";
      mp['9']="wxyz";

      vector<string>ans;
      string temp;
      solve(0,digits,temp,ans,mp);
      return ans;
    }
};