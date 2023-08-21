#include<bits/stdc++.h>
using namespace std;

/*

*/
class Solution {
public:
    bool checkValidString(string s) {
   stack<int> st ,st1;
    
    for (int i = 0; i < s.size(); i++) {
       if(s[i]=='(')st.push(i);
       else if(s[i]=='*')st1.push(i);
       else{
           if(!st.empty())st.pop();
           else if(!st1.empty())st1.pop();
           else return false;
       }
    }
    
    while (!st.empty() && !st1.empty() && !st1.empty() && st1.top()>st.top()) {
       st.pop();
       st1.pop();
    }
    
    return st.empty();
    }
};