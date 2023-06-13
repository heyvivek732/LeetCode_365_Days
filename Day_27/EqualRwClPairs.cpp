#include<bits/stdc++.h>
using namespace std;
/*
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

  [[3,2,1],
  [1,7,6],
  [2,7,7]];

Row -> 3,2,1  1,7,6  2,7,7
col -> 3,1,2  2,7,7  1,6,7
 Ans : -> rw-> 2,7,7
        col -> 2,7,7
*/
int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int cnt=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            mp[grid[i]]++;
        }
        for(int i=0;i<n;i++){
          vector<int>temp;
            for(int j=0;j<n;j++){
                temp.emplace_back(grid[j][i]);
            }
            cnt+=mp[temp];
        }
        return cnt;
    }