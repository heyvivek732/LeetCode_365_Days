#include<bits/stdc++.h>
using namespace std;

/*
Input:
n = 4
a = {3, 4, 1, 5}
Output:
5
Explanation:
We can buy stock on day 1 (at price 3) and sell it on 
day 2 (at price 4) profit will be 4-3=1, 
We can buy another stock on day 3 (at price 1) and sell 
it on day 4 (at price 5) profit will be 5-1=4, 
which will give us maximum profit of 5.
Example 2:

Input:
n = 5
a = {1, 3, 5, 7, 9}
Output:
8
Explanation:
We can buy stock on day 1 (at price 1) and sell it on 
day 5 (at price 9), 
which will give us maximum profit of 8.
*/


 int stockBuyAndSell(int n, vector<int> &prices) {
        int maxProfit=0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1]){
                maxProfit+=(prices[i+1]-prices[i]);
            }
        }
        return maxProfit;
    }