#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
double CheckTime(vector<int>&dist,int speed){
         double req_time=0.0;
           for(int i=0;i<dist.size();i++){
              req_time+=(double)dist[i]/(double)speed;
              if(i!=dist.size()-1){
                  req_time=ceil(req_time);
              }
           }
           return req_time;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
       int n=dist.size();
       int low=1;
       int high=1e7;
       int minSpeed=-1;
       while(low<=high){
           int mid=(low+high)>>1;
           if(CheckTime(dist,mid)<=hour){
               minSpeed=mid;
               high=mid-1;
           }
           else {
               low=mid+1;
           }
       }
       return minSpeed;
    }
};