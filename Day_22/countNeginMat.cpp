#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int countNegatives(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       int rw=m-1,cl=0;
       int cnt=0;
       while(rw>=0 && cl<n){
           if(grid[rw][cl]<0){
               --rw;
               cnt+=n-cl;
           }else{
               cl++;
           }
       }
       return cnt;
    }
};