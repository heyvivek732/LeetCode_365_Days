#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Solution: 1 :-Recursion With memoization TC:(m*n)

    int solve(int ind, int amount, vector<int> &coins, int n, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 1;
        if (amount < 1 || ind >= n)
            return 0;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int pick = solve(ind, amount - coins[ind], coins, n, dp);
        int notpick = solve(ind + 1, amount, coins, n, dp);

        return dp[ind][amount] = pick + notpick;
    }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(0, amount, coins, coins.size(), dp);
    }

    // Solution 2 :- Dp

    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};