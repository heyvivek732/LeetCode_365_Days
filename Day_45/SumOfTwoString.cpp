#include<bits/stdc++.h>
using namespace std;
/*
Input:
X = "25", Y = "23"
Output:
48
Explanation:
The sum of 25 and 23 is 48.
*/
 string findSum(string s1, string s2) {
       string ans="";
       int i=s1.size()-1;
       int j=s2.size()-1;
       int carry=0;
       while(i>=0 || j>=0 || carry){
           long sum=0;
          if(i>=0){
           sum+=s1[i]-'0';
           i--;
          }
          if(j>=0) {
          sum+=s2[j]-'0';
          j--;
          }
          sum+=carry;
          carry=sum/10;
          sum=sum%10;
          
          ans+=to_string(sum);
       }
       reverse(ans.begin(),ans.end());
       int cnt=0;
       for(int i=0;i<ans.size();i++){
           if(ans[i]=='0')cnt++;
           else break;
       }
       if(cnt==ans.size()) return "0";
       string res="";
       for(int i=cnt;i<ans.size();i++)res+=ans[i];
       
       return res;
    }