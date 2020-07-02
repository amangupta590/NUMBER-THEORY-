#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vv vector<int>
#define p 1000000007
int f[1000001];
int power(int a,int n){
	int res=1;
	while(n){
		if(n%2==1){
			res=(res * (ll)*a)%p;
			n--;
		}
		else{
			a=(a*(ll)*a)%p;
			n/=2;
		}
	}
	return res;
}
int c(int n,int k){
	if(k>n){
		return 0;
	}
	int res=f[n];
	//if we dividing some numbers so we generally find the inverse of that number
	res=(res* ll *power(f[k],p-2))%p;
	res=(res* ll *power(f[n-k],p-2))%p;
	
	return res;
}
int main(){
	f[0]=f[1]=1;
	for(int i=2;i<=1000000;i++){
		f[i]=(f[i-1]*(ll)i)%p;
	}
	int q;
	int n,k;
	while(q--){
		cin>>n>>k;
		cout<<c(n-k)<<endl;
	}
	return 0;
}
