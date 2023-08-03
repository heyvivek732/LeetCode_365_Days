#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
         string st="";
        vector<int> visited (26,0), freq(26,0);
        for(auto it: s) freq[it-'a']++;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a']!=0) continue;
            while(!st.empty() && st.back()>s[i] && freq[st.back()-'a']>0){
                visited[st.back()-'a']=0;
                st.pop_back();
            }
            visited[s[i]-'a']=1;
            st.push_back(s[i]);
        }
        return st;
    }
};