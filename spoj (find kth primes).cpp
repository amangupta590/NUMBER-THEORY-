#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>primes;
bool arr[90000001];

void sieve(){
    int maxn=90000000;
    arr[0]=arr[1]=true;
    for(int i=2;i*i<=maxn;i++){
        if(arr[i]==false){
            for(int j=i*i;j<=maxn;j=j+i){
                arr[j]=true;
            }
        }
    }
    for(int i=2;i<=maxn;i++){
        if(arr[i]==false)
            primes.push_back(i);
    }

}
int main() {
    int q,n;
    cin>>q;
    sieve();
    while(q--){
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
	

	return 0;
}