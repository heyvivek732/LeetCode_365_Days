#include<bits/stdc++.h>
using namespace std;
/*
In a base10 system, 58 is
10 * 5 + 8.
58 is represented by the sixth digit, and the ninth digit in the base10 system where 0 does exist.

In base26 system, the number 58 is actually
26 * 2 + 6.
Therefore, it is represented by the second letter + the sixth letter, which is 'BF' in this case.

Conclusively, we can keep modding/dividing to get the last character in the base26 system.
*/
class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
         if(n<=26){
            string temp="";
            temp+='A'+(n-1)%26;
            return temp;
         }
          while(n>0){
            if(n%26==0){
             ans+='A'+25;
              n-=1;
            }else{
              ans+='A'+n%26-1;
          }
        n/=26;
      }
     reverse(ans.begin(),ans.end());
     return ans;
    }
};