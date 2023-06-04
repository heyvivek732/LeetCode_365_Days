#include<bits/stdc++.h>
using namespace std;
// Test Casess
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
/*
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/

// Using Recursion
string decode(string &s,int &ind){
        string ans;
        while(ind<s.length() && s[ind]!=']'){
            if(isdigit(s[ind])){
                int cnt=0;
                while(isdigit(s[ind])){
                    cnt=cnt*10+(s[ind]-'0');
                    ind++;
                }
                ind++;
               string temp=decode(s,ind);
                while(cnt-- >0){
                    ans+=temp;
                }
                ind++;
            }else{
                ans+=s[ind];
                ind++;
            }
        }
        return ans;
    }
    string decodeString(string s) {
      int i=0;
        return decode(s,i);
}

// Using Stack
 string decodeString(string s) {
      stack<int>num;
      stack<string>str;
      string ans="";
        int ind=0;
        while(ind<s.size()){
            if(isdigit(s[ind])){
                int cnt=0;
                while(isdigit(s[ind])){
                    cnt=cnt*10+(s[ind]-48);
                    ind+=1;
                }
                num.push(cnt);
            }
            else if(s[ind]=='['){
                str.push(ans);
                ans="";
                ind+=1;
            }
            else if(s[ind]==']'){
                string res=str.top();
                str.pop();
                int n=num.top();
                num.pop();
                for(int i=0;i<n;i++){
                    res+=ans;

                }
                ans=res;
                 ind+=1;
               
            }else{
               ans+=s[ind];
                ind+=1;
            }
        }
        return ans;
    }