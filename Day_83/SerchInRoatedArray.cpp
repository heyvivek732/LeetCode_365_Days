#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int getPivot(vector<int>& arr,int n){
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=arr[0]){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;
}
int binarySe(vector<int>& arr,int l,int h,int target){
    int low=l;
    int high=h;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int pivot=getPivot(arr,n);
       if(target>=arr[pivot] && target<=arr[n-1]){
           return binarySe(arr,pivot,n-1,target);
       }else{
           return binarySe(arr,0,pivot-1,target);
       }
    }
};