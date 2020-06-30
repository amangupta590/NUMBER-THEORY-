// firstly we store all prime number in array just like 2,3,5,7 using sieve of erotosthenes with complexity O(n log( log n)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector
vv<int>primesieve(int *p,int n){
    p[0]=0,p[1]=0,p[2]=1;
    for(int i=3;i<=n;i+=2){
        p[i]=1;
    }
    for(int i=3;i<=n;i+=2){
        if(p[i]==1){
            for(int j=i*i;j<=n;j+=2*i){
                p[i]=0;
            }
        }
    }
    vv<int>primes;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2){
        primes.push_back(i);
    }
    return primes;
}
vv<int>factorize(int m,vv<int>&primes){
    vv<int>factors;
    factors.clear();

    int i=0;
    int p=primes[0];
    while(p*p<=m){
        if(m%p==0){
            factors.push_back(p);
            while(m%p==0){
                m=m/p;
            }
        }
        i++;
        p=primes[i];
    }
    if(m!=1){
        factors.push_back(m);
    }
    return factors;
}
int main() {
    int n=1000000;
    int p[n];
    for(int i=0;i<=n;i++){
        p[i]=0;
    }
    vv<int>primes=primesieve(p,100);
    
    int t;
    cin>>t;
    while(t--){
        int no;
        cin>>no;
        vv<int>factors=factorize(no,primes);
        for(auto f:factors){
            cout<<f<<" "<<endl;
        }
    }
    return 0;
}
