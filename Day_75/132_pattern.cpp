#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        stack<int>st;
        int a=INT_MIN;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(arr[i]<a)return true;

            while(!st.empty() && arr[i]>st.top()){
                a=st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return false;
    }
};