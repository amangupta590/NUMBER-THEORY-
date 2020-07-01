#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector<int>
#define pb push_back
ll fastexpo(ll a,ll b,ll m){
	ll res=1;
	while(b>0){
		if(b&1){
			res=(res*a)%m;
		}
		a=(a*a)%m;
		b=b>>1;
	}
	return res;
}
int main(){
	//fast modulo exponentiation  (a^b%m)
	//in recursion O(logn) with O(logn)space
	//bitmasking O(log n) and O(1) sapce
	cout<<fastexpo(5,3,1000)<<endl;
	return 0;	
}
