#include<bits/stdc++.h>
using namespace std;

//Greedy DP
/*
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int selling=0,buy=INT_MIN;
        for(auto it:prices){
            int tmp=selling;
            selling=max(selling,buy+it);
            buy=max(buy,tmp-it-fee);
        }
        return selling;
    }
};