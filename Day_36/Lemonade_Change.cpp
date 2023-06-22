#include<bits/stdc++.h>
using namespace std;
/*
Input:
N = 5
bills [ ] = {5, 5, 5, 10, 20}
Output: True
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change we return true.
*/
 bool lemonadeChange(int n, vector<int> &bills) {
       int cnt_five=0,cnt_ten=0,cnt_20=0;
       for(int i=0;i<n;i++){
           if(bills[i]==5){
               cnt_five++;
           }
           else if(bills[i]==10){
               if(cnt_five<1){
                   return false;
               }
                   cnt_five--;
                   cnt_ten++;
           }
           else if(bills[i]==20){
               cnt_20++;
               if(cnt_ten<=0){
                   if(cnt_five<3){
                       return false;
                   }
                   cnt_five-=3;
               }else{
                  if(cnt_ten<1 && cnt_five<1) return false;
                  
                  cnt_ten--;
                  cnt_five--;
               }
           }
       }
      return (cnt_five<0 || cnt_ten<0 || cnt_20<0)?false:true;
    }