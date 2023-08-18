#include<bits/stdc++.h>
using namespace std;
/*
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

INTUITION 
 1. DIVIDE THE MATRIX IN ARRAY FORM 
 2. EACH ARRAY WE CAN FIND THE MAX RACTANGLE IN HISTOGRAM 
 3.AFTER THAT WE ADD PREVIOUS ARR TO THIS CURR ARRAY AND THEN FIND THE MAX RACTANGLE IN HISTROGRAM 

 AFTER THAT MAKE NEW ARRAY COPY INTEGER 
 THEN TRAVERSE IN NEW ARRAY AND CHECK THE CONDITION IF CURR POSITION IS NOT ZERO THAN ADD THE ELEMENT 

 

         0   0   0   0   0      Max Ractangle in Histogram
         +   +   +   +   +
 EX := ["1","0","1","0","0"]
         1   0   1   0   0   =>  1
         +   +   +   +   + 
      ,["1","0","1","1","1"]  
         2   0   2   1   1   =>  3
         +   +   +   +   + 
      ,["1","1","1","1","1"],
         3   1   3   2   2   =>  6
         +   +   +   +   + 
       ["1","0","0","1","0"]
         4   1   3   3   2   =>  6
                           max => 6  ans

*/
class Solution {
public:
int LargestHistogram(vector<int>&arr){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
       int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=matrix[i][j]-'0';
            }
        }

        int area=LargestHistogram(arr[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=0){
                    arr[i][j]=arr[i][j]+arr[i-1][j];
                }
                else arr[i][j]=0;
            }
            int newArea=LargestHistogram(arr[i]);
            area=max(newArea,area);
        }
        return area;
        
    }
};