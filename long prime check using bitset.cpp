#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll n=10000000;
bitset<10000000>b;
vector<ll>primes;
void sieve(){
    b.set();
    b[0]=b[1]=0;
    for(ll int i=2;i<=n;i++){
        if(b[i]){
            primes.push_back(i);
            for(ll int j=i*(ll)i;j<=n;j=j+i){
                b[j]=0;
            }
        }
    }
}
int main() {
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        cout<<primes[a-1]<<endl;
    }    
    return 0;
}
