#include<bits/stdc++.h>
using namespace std;
/*
Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 
6
Explanation: 
In the given array arr[1] < arr[7]  satisfying 
the required condition (arr[i] <= arr[j])  thus 
giving the maximum difference of j - i which is
6(7-1).
Example 2:

Input:
N = 2
arr[] = {18, 17}
Output: 
0
Explanation: 
We can either take i and j as 0 and 0 
or we cantake 1 and 1 both give the same result 0.
*/
 int maxIndexDiff(int arr[], int n) {
        int maxi=0;
        int i=0,j=n-1;
        while(j>i){
            if(arr[j]>=arr[i]){
                maxi=max(maxi,j-i);
                i++;
                j=n-1;
            }else{
                j--;
            }
        }
        return maxi;
    }