#include<bits/stdc++.h>
using namespace std;
// Time Complexity O(sqrt(n))
int phi(int n){
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i;
            res*=(i-1);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1){
        res/=n;
        res*=(n-1);
    }
    return res;
}
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<"ETF "<<n<<" -> "<<phi(n)<<endl;
    }
    return 0;    
}
