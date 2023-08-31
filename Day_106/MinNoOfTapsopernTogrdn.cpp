#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>arr(n+1);
        for(int i=0;i<ranges.size();i++){
            if(ranges[i]==0)continue;
            int left=max(0,i-ranges[i]);
            arr[left]=max(arr[left],i+ranges[i]);
        }
        
        int cnt=0,reach=0,end=0;
        for(int i=0;i<arr.size() && end<n;end=reach){
            cnt++;
            while(i<arr.size() && i<=end){
                reach=max(reach,arr[i++]);
            }
            if(end==reach)return -1;
        }
        return cnt;
    }
};