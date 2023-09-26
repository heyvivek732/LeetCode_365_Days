#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=0,j=0;
       int cnt=0;
       while(i<t.size()){
           if(t[i]==s[j]){
               cnt++;
               i++;
               j++;
           }
           else{
               i++;
           }
       }
       return cnt==s.size();
    }
};