// optimised approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector
void primefactor(int n){
    vv<pair<int,int>>factors;
    int cnt;
     for(int i=2;i*i<=n;i++){
         if(n%i==0){
             while(n%i==0){
                 cnt++;
                 n=n/i;
             }
             factors.push_back(make_pair(i,cnt));
         }
     }
     if(n!=1){
         factors.push_back(make_pair(n,1));
     }
     for(auto p:factors){
         cout<<p.first<<" , "<<p.second<<endl;
     }
     return ;
}
int main(){
    int n;
    cin>>n;
    primefactor(n);
}