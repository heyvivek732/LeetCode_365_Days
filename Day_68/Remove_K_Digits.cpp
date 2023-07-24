#include<bits/stdc++.h>
using namespace std;

/*
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char>st;
       string ans="";
      for(int i=0;i<num.size();i++){
          if(st.empty())st.push(num[i]);

          else if(st.top()>num[i]){
              while(!st.empty() && st.top()>num[i] && k>0){
                  st.pop();
                  k--;
              }
              st.push(num[i]);
          }
          else if(st.top()<=num[i])st.push(num[i]);
      }
      while(k>0){
          st.pop();
          k--;
      }
      while(!st.empty()){
          ans+=st.top();
          st.pop();
      }
      reverse(ans.begin(),ans.end());
      if(ans=="")return "0";
      // Handle Leading Zero
      int i=0;
     string temp="";
      while(ans[i]=='0')i++;
      temp=ans.substr(i,ans.size()-i);

      if(i>0)return temp!=""?temp:"0";
      return ans;
    }
};