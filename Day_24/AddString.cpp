#include<bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2) {
       int n=num1.size(),n1=num2.size();
        string ans="";
        int i=n-1,j=n1-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            long num=0;
           if(i>=0){
               num+=(num1[i]-'0');
               i--;
           }
           if(j>=0){
               num+=(num2[j]-'0');
               j--;
           }
           num+=carry;
           carry=num/10;
           num=num%10;

           ans+=to_string(num);
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }  