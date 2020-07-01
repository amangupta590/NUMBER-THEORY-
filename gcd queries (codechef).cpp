#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vv vector<int>
#define mod 1000000007
int pre[100005],suff[100005];
int arr[10001];
int gcd(int a,int b){
	if(b==0)	return a;
	return gcd(b,a%b);
}
int main(){
	int t,q,n,l,r;
	cin>>t;
	while(t--){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		pre[0]=suff[n+1]=0;
		for(int i=1;i<=n;i++){
			pre[i]=gcd(pre[i-1],arr[i]);
		}
		for(int i=n;i>=1;i--){
			suff[i]=gcd(suff[i+1],arr[i]);
		}
		while(q--){
			cin>>l>>r;
			cout<<gcd(pre[l-1],suff[r+1])<<endl;
		}
	}
	return 0;
}
