#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
#define ll long long int
#define mod 1000000007
#define fr(i,a,b) for(long long int i=a;i<b;i++)
ll dp[1000000];
ll power(ll a,ll n){
	int res=1;
	while(n){
		if(n%2){
			res=(res*1LL*a)%mod;
            n-=1;
		}
		else{
			a=(a*1LL*a)%mod;
            n/=2;
		}
	}
	return res;
}
ll C(ll n,ll k){
    if(k>n)
    return 0;
    ll res=dp[n];
    res=(res*1LL*power(dp[k],mod-2))%mod;
    res=(res*1LL*power(dp[n-k],mod-2))%mod;
    return res;
}
int main(){
	dp[0]=dp[1]=1;
    for(ll i=2;i<=1000000;i++){
        dp[i]=(dp[i-1]*1LL*i)%mod;
    }
    ll n,k;
    cin>>n>>k;
    cout<<C(n,k)<<endl;
	return 0;
}
