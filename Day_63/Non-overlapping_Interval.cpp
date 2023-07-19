#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=-1;
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),compare);
        vector<int> temp=intervals[0];
        
        for(auto it:intervals){
            if(temp[1]>it[0]) ans++;
            else temp=it;
        }
        return ans;
    }
};