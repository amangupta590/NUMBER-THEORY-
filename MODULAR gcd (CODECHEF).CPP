#inlcude<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vv vector<int>
#define mod 1000000007
ll power(ll a,ll n,ll d){
	ll res=1;
	while(n){
		if(n%2){
			res=()(res%d)*(a%d)) %d;
			n--;
		}
		else{
			a=((a%d)*(a%d))%d;
			n/=2;
		}
	}
	return res;	
}
ll gcd(ll a,ll b,ll n){
	if(a==b){
		return (power(a,n,mod) + power(b,n,mod)	)%mod;	
	}
	ll candi=1;
	ll num=a-b;
	for(int i=1;i*i<=num;i++){
		if(num%i==0){
			ll tmp=(power(a,n,i)+power(b,n,i))%i
			if(tmp==0){
				candi=max(candi,i);
			}
			tmp=(power(a,n,num/i)+power(b,n,num/i))%(num/i);
			if(tmp==0){
				candi=max(candi,num/i);
			}
		}
	}
	return candi%mod;
}
int main(){
	ll t;
	ll a,b,n;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		cout<<gcd(a,b,n)<<endl;
	}
	return 0;
}
