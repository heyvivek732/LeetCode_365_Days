#include<bits/stdc++.h>
using namespace std;

/*
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
      if(s.size()!=goal.size())return false;
      if(s==goal){
      set<char>temp(s.begin(),s.end());
      return temp.size()<goal.size();
      }
      int i=0,j=s.size()-1;
      while(i<j && s[i]==goal[i])i++;
      while(j>=0 && s[j]==goal[j])j--;
      if(i<j)swap(s[i],s[j]);
      return s == goal;
    }
};