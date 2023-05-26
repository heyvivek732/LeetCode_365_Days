#include<bits/stdc++.h>
using namespace std;
/*
There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
*/

//First Approache

  int findVal(string s,int val){
      if(s[0]=='+' || s[1]=='+'){
          val=val+1;
      }
      else if(s[0]=='-' || s[1]=='-'){
          val= val-1;
      }
      return val;
  }
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        int res=0;
        for(int i=0;i<operations.size();i++){
            ans=findVal(operations[i],0);
            res+=ans;
        }
        return res;
 }
// Second approaches
int finalValueAfterOperations(vector<string>& s) {
        int ans=0;
        int res=0;
        for(int i=0;i<s.size();i++){
           if(s[i][0]=='+' || s[i][1]=='+'){
               res+=1;
           }
           else if(s[i][0]=='-' || s[i][1]=='-'){
               res-=1;
           }  
        }
        return res;
    }