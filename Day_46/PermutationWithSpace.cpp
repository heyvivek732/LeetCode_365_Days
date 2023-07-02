#include<bits/stdc++.h>
using namespace std;

/*
Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
*/
 void solve(int ind,string s,vector<string>&ans,string temp){
      if(temp[0]==' ') return;
      
      if(ind==s.size()){
          if(temp[temp.size()-1]!=' ')ans.push_back(temp);
          return;
      }
      solve(ind+1,s,ans,temp+" "+s[ind]);
      solve(ind+1,s,ans,temp+s[ind]);
  }
    vector<string> permutation(string s){
       vector<string>ans;
       string temp="";
       solve(0,s,ans,temp);
       return ans;
    }