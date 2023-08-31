#include<bits/stdc++.h>
using namespace std;

/*
Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is
*/
class Solution {
public:
    int bestClosingTime(string customers) {
        int mini=INT_MAX;
        int minInd=0;
        int suff_cnt=0;
        int pref_cnt=0;
        for(auto it:customers){
            if(it=='Y')suff_cnt++;
        }
        for(int i=0;i<customers.size();i++){
            if(mini>(pref_cnt+suff_cnt)){
                mini=pref_cnt+suff_cnt;
                minInd=i;
            }
            if(customers[i]=='N')pref_cnt++;
            else{
               suff_cnt--;
              if(suff_cnt<0)suff_cnt=0;
            }
        }
        if(mini>(pref_cnt+suff_cnt)){
            mini=pref_cnt+suff_cnt;
            minInd=customers.size();
        }
        return minInd;
    }
};