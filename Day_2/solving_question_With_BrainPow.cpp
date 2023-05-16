#include<bits/stdc++.h>
using namespace std;

/*
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.


Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

*/


// Iterative Approaches
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
      int n=questions.size();
      vector<long long>dp(n+1,0);
      for(int i=n-1;i>=0;i--){
        int points=questions[i][0],jump=questions[i][1];
         dp[i]=max(points+dp[min(jump+i+1,n)],dp[i+1]);
      }

      return dp[0];
    }
};
 

// Recursive With Dfs
class Solution {
public:
long long solve(vector<vector<int>>&arr,int i,vector<long long>&dp){
    if(i>=arr.size()) return 0;

    if(dp[i]>0) return dp[i];

    int points=arr[i][0],jump=arr[i][1];

    return dp[i]=max(solve(arr,i+1,dp),points+solve(arr,i+jump+1,dp));

}
    long long mostPoints(vector<vector<int>>& questions) {
      vector<long long>dp(questions.size(),0);

      return solve(questions,0,dp);
    }
};