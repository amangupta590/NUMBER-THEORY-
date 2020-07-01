#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vv vector<int>
#define mod 1000000007
ll arr[3];
ll I[3][3], T[3][3];
void mul(ll A[3][3]  ,ll B[3][3], int dim){
	ll res[dim+1][dim+1];
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			res[i][j]=0;
			for(int k=1;k<=dim;k++){
				
				ll x=(A[i][k] * B[k][j])%mod;
				res[i][j]=(res[i][j] +x)%mod;
				
			}
		}
	}
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			A[i][j]=res[i][j];
		}
	}
}
ll getfibo(int n){
	if(n<=2){	
		return arr[n];
	}
	I[1][1]=I[2][2]=1;
	I[1][2]=I[2][1]=0;
	
	T[1][1]=0,T[1][2]=1,T[2][1]=1,T[2][2]=1;
	n=n-1;
	while(n){
		if(n%2==1){
			mul(I,T,2),n--;
			
		}
		else{
			mul(T,T,2),n/=2;
		}
	} 
	ll fin=(arr[1]*I[1][1] +arr[2]*I[2][1])%mod;
	return fin;
	
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>arr[1]>>arr[2]>>n,
		n++;
		cout<<getfibo(n)<<endl;
	}
	
	return 0;
}
