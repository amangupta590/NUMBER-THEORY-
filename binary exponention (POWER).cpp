#include <bits/stdc++.h>
using namespace std;
#define ll long long
//binary exponentiation
int power(int a ,int base){
    int res=1;
    while(base){
        if(base%2){
            res*=a,base--;
        }
        else{
            a=a*a;
            base/=2;
        }
    }
    return res;
}
int main() {
    int a=20;
    int base=100;
    cout<<power(a,base);
}
