#include<bits/stdc++.h>
using namespace std;
/*
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
*/
 int countSegments(string s) {
       int cnt=0;
        s.push_back(' ');
        for(int i=1;i<s.size();i++){
            if(s[i]==' ' && s[i-1]!=' '){
                cnt++;
            }
        }
        return cnt;
    }