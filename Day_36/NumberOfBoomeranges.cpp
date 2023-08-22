#include<bits/stdc++.h>
using namespace std;

// Array ,Map
/*
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
*/
int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
       for(int i=0;i<n;i++){
           map<int,int>mp;
           for(int j=0;j<n;j++){
               int dis=((points[i][0]-points[j][0])*(points[i][0]-points[j][0])) + ((points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
               mp[dis]++;
           }
           for(auto it:mp){
               if(it.second) res+=(it.second*(it.second-1));  // n*n-1 possible Boomeranges
           }
       }
        return res;
    }