#include<bits/stdc++.h>
using namespace std;

/*
Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.
*/
class Solution {
public:
// Two Case 
//  1-> Either F to T
//  2-> Either T to F
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        int j=0,cnt=0,maxlen=0;
    // case 1 -> F to T
        for(int i=0;i<n;i++){
            if(s[i]=='F')cnt++;
            while(cnt>k){
                if(s[j]=='F')cnt--;
                j++;
            }
            maxlen=max(maxlen,i-j+1);
      }
  // case 2 -> T To F
  
      cnt=0,j=0;
      for(int i=0;i<n;i++){
          if(s[i]=='T')cnt++;
          while(cnt>k){
              if(s[j]=='T')cnt--;
              j++;
          }
          maxlen=max(maxlen,i-j+1);
      }
      return maxlen;
    }
};