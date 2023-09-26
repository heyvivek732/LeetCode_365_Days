#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isPred(string &s,string &s1){
    if(s.size()!=s1.size()+1)return false;
    int cnt=0,i=0,j=0;
    while(i<s.size()){
        if(s[i]==s1[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return (i==s.size() && j==s1.size())?true:false;
}
    int longestStrChain(vector<string>& words) {
        vector<int>dp(words.size(),1);
        sort(words.begin(),words.end(),[](string s1,string s2){
            return s1.size()<s2.size();
        });
        int ans=INT_MIN;
        for(int i=0;i<words.size();i++){ 
           for(int j=0;j<i;j++){
               if(isPred(words[i],words[j]) && dp[j]+1>dp[i]){
                   dp[i]=dp[j]+1;
               }
           }
           ans=max(ans,dp[i]);
        }
        return ans;
    }
};