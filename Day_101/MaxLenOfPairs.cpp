#include<bits/stdc++.h>
using namespace std;

/*
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

*/
int maxLenPair(vector<vector<int>>&arr){
    sort(arr.begin(),arr.end(),[](const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    });
    int cnt=1;
    int end=arr[0][1];
    for(int i=1;i<arr.size();i++){
        if(arr[i][0]>end){
            end=arr[i][1];
            cnt++;
        }
    }
    return cnt;
}