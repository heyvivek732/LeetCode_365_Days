#include<bits/stdc++.h>
using namespace std;

/*
Largest Number
 Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/
bool cmp(string a,string b){
    return a+b>b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        string ans="";

        for(auto it:nums) arr.push_back(to_string(it));

        sort(arr.begin(),arr.end(),cmp);

        if(arr[0][0]=='0') return "0";

        for(auto it:arr)ans+=it;
        
        return ans;
    }
};