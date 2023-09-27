#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
      long long len=0;
      int n=s.size();
      for(auto it:s){
          if(isdigit(it)){
              len*=it-'0';
          }
          else{
              len++;
          }
      }

      for(int i=n-1;i>=0;i--){
          if(isdigit(s[i])){
              len/=(s[i]-'0');
              k=k%len;
          }else{
              if(k==0 || k==len){
                  return string("")+s[i];
              }
              len--;
          }
      }
      return "";
    }
};