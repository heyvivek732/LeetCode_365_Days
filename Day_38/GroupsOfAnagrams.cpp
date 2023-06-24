#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
  string strSort(string s){
    int count[26]={0};
    for(char c:s){
      count[c-'a']++;
    }
    string t;
    for(int i=0;i<26;i++){
      t+=string(count[i],i+'a');
    }
    return t;
  }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
       unordered_map<string,vector<string>>mp;
       for(auto str:strs){
        mp[strSort(str)].push_back(str);
       }

       for(auto it:mp) ans.push_back(it.second);

       return ans;
    }

};
// Using HashMap and Sorting
/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
       unordered_map<string,vector<string>>mp;

       for(int i=0;i<strs.size();i++){
         string s=strs[i];
         sort(strs[i].begin(),strs[i].end());  // aet -> tea ,eat,ate
                                              //  ant -> tan,nat
                                             //   abt -> bat 
         mp[strs[i]].push_back(s);
       }

       for(auto it:mp) ans.push_back(it.second);

       return ans;
    }
};