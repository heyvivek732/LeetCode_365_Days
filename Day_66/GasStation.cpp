#include<bits/stdc++.h>
using namespace std;
/*
 Gas Station
gas => 1 -> 2 -> 3 -> 4 -> 5 -> 
cost =>   3    4    5    1    2

to find  = gas[i]-cost[i]  if (-ve) then reset and point to other solution because in less amount can't traverse

*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int dis=0;
        int fuel=0;
        int next=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            dis+=diff;
            fuel+=diff;
            if(fuel<0){
               next=i+1;
               fuel=0;
            }
        }
        return dis<0?-1:next;
    }
};