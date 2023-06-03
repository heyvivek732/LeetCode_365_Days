#include <bits/stdc++.h>
using namespace std;
bool isPalidrome(string s, int low, int high)
{
    while (low < high)
    {
        if (s[low++] != s[high--])
            return false;
    }
    return true;
}
int solve(int ind, int n, string s, int ans, vector<int> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind] != -1)  // Memoization
        return dp[ind];

    for (int i = ind; i < n; i++)
    {
        int temp = 0, flag = 0;
        if (isPalidrome(s, ind, i))
        {
            temp = 1 + solve(i + 1, n, s, ans, dp); // Counting Into dp
            flag = 1;
        }
        if (flag)
            ans = min(temp, ans);
    }
    return dp[ind] = ans;
}
int palindromicPartition(string str)
{
    int n = str.size();
    int ans = INT_MAX;
    vector<int> dp(n + 1, -1);
    return solve(0, n, str, ans, dp) - 1;
}