#include<bits/stdc++.h>
using namespace std;
/*
Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
*/
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
         
         vector<pair<int,int>>temp;
         long long ans=0,sum=0;
         for(int i=0;i<nums1.size();i++){
             temp.push_back({nums2[i],nums1[i]});
         }

         sort(temp.rbegin(),temp.rend());
         
         priority_queue<int>min_heap;
          for(int i=0;i<k-1;i++){
              sum+=temp[i].second;
               min_heap.push(-temp[i].second);
         }

         for(int i=k-1;i<nums1.size();i++){
               sum+=temp[i].second;
              min_heap.push(-temp[i].second);

              ans=max(ans,sum*temp[i].first);
              sum+=min_heap.top();
              min_heap.pop();
         }
         return ans;
    }