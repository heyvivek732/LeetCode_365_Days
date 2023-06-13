#include<bits/stdc++.h>
using namespace std;

/*
 N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.
*/
vector<int> kLargest(int arr[], int n, int k) {
     sort(arr,arr+n,greater<int>());
	   vector<int>v;
	   for(int i=0;i<k;i++){
	       v.push_back(arr[i]);
	   }
	   return v;
	}