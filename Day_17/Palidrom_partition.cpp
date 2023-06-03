#include<bits/stdc++.h>
using namespace std;
/*Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
 
 Input:  s = "aabb"
 output : [["a","a","b","b"],["a","a","bb"],["aa","b","b"],["aa","bb"]]

*/
class Solution {
public:
bool isPalidrom(string s,int low,int high){
   while(low<=high){
       if(s[low++]!=s[high--]) return false;
   }
   return true;
}
void solve(int ind,string s,vector<vector<string>>&ans,vector<string>&temp){
  if(ind==s.size()){
      ans.push_back(temp);
      return;
  }
  for(int i=ind;i<s.size();i++){
      if(isPalidrom(s,ind,i)){
        temp.push_back(s.substr(ind,i-ind+1));
         solve(i+1,s,ans,temp);
         temp.pop_back();
      }
  }
}
 vector<vector<string>> partition(string s) {
     vector<vector<string>>ans;
     vector<string>temp;
     solve(0,s,ans,temp);
    return ans;
    }
};