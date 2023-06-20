#include<bits/stdc++.h>
using namespace std;


/*
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    int  n=gain.size();
    int prefSum=0;
    int  altitude=0;
    for(int i=0;i<n;i++){
        prefSum+=gain[i];
        altitude=max(altitude,prefSum);
    }
    return altitude;
    }
};