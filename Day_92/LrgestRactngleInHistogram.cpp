#include<bits/stdc++.h>
using namespace std;

/*
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

        [2,1,5,6,2,3]
        for every element i We find out previous smaller and next smaller element in array 
        and then we got width and then multiply them with arr[i] ot get and

*/
/*
Approach 1 : Brute Force 
TC O(N*N) SC:O(1)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j>=0){
                if(j-1>=0 && arr[i]<=arr[j-1])j--;
                else break;
            }
            int k=i;
            while(k<n){
                if(k+1<n && arr[i]<=arr[k+1])k++;
                else break;
            }
            int temp=(k-j+1)*arr[i];
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};
/*
Approach 2 : Optimal Solution
  TC: O(3N) SC:O(N)
*/
    int largestRectangleArea(vector<int>& arr) {
        int maxi=INT_MIN;
        int n=arr.size();
        stack<int>st;
        vector<int>nxt_smll(n),prev_smll(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            prev_smll[i]=(!st.empty())?st.top()+1:0;
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            nxt_smll[i]=(!st.empty())?st.top()-1:n-1;

            st.push(i);
        }
        for(int i=0;i<n;i++){
          int area=(nxt_smll[i]-prev_smll[i]+1)*arr[i];
          maxi=max(maxi,area);
        }
        return maxi;
    }