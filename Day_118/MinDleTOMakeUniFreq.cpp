#include<bits/stdc++.h>
using namespace std;
/*
Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
*/
class Solution {
public:
    int minDeletions(string s) {
      vector<int>freq(26);
      for(auto it:s)freq[it-'a']++;
      unordered_map<int,int>mp1;
      int cnt=0;
      for(int i=0;i<freq.size();i++){
          if(mp1.find(freq[i])!=mp1.end()){
              int a=freq[i];
              while(a){
                 if(mp1.find(a)!=mp1.end()){
                     a--;
                     cnt++;
                 } 
                 else{
                     mp1[a]++;
                     break;
                 }
              }
          }
          else{
              mp1[freq[i]]++;
          }
      }
      return cnt;
    }
};