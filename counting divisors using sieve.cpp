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
int no_of_divisiors(int m,vv<int>&primes){
    int i=0;
    int p=primes[0];
    int ans=1;
    while(p*p<=m){
        if(m%p==0){
            int cnt=0;
            while(m%p==0){
                cnt++;
                m=m/p;
            }
            ans=(cnt+1)*p;
        }
        i++;
        p=primes[i];
    }
    if(m!=1){
        ans=ans*2;
    }
    return ans;
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
        int divs=no_of_divisiors(no,primes);
        cout<<divs<<endl;
    }
    return 0;
}
