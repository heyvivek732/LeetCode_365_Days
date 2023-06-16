#include<bits/stdc++.h>
using namespace std;


/*
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
*/
int characterReplacement(string s, int k) {
       int n=s.size();
    
        int max_len=0;
        int max_cnt=0;
        int freq_count[26]={0};
        int j=0,i=0;
        for(;i<n;i++){
          freq_count[s[i]-'A']++;
          int max_char_cnt=freq_count[s[i]-'A'];
         max_cnt=max(max_cnt,max_char_cnt);
            
          if((i-j+1)-max_cnt>k){
              freq_count[s[j]-'A']--;
              j++;
          }
            
            max_len=max(max_len,i-j+1);
            
        }
        return max_len;
}