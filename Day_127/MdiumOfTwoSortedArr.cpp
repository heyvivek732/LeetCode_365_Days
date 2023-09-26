#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
         int n=arr1.size();
        int m=arr2.size();
        vector<int>final(n+m,0);
        int i=0,j=0;
        int k=-1;
        while(i<n && j<m){
            if(arr1[i]<=arr2[j]){
                final[++k]=arr1[i++];
            }else{
                final[++k]=arr2[j++];
            }
        }
        while(i<n){
            final[++k]=arr1[i++];
        }
        while(j<m){
            final[++k]=arr2[j++];
        }
        int n1=n+m;
        if(n1%2==0){
            return  (final[n1/2-1]+final[n1/2])/2.0;
        } else{
            return final[n1/2];
        }
    }
};