#include<bits/stdc++.h>
using namespace std;
int elimination_game(int n){
    if(n==1) return 1;

    int left=n/2;
    int right=elimination_game(n/2);

    return 2*(left-right+1);
}
int main(){
    int n;
    cout<<"Enter The Number"<<endl;
    cin>>n;
    int a=elimination_game(n);
    cout<<"The last Player is : "<<a<<endl;
    return 0;
}