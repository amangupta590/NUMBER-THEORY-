#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
lli dp[1000001];
lli inv[1000001];
// void init_code(){
//     #ifndef ONLINE_JUDGE
//     freopen("./input.txt", "r", stdin);
// 	freopen("./output.txt", "w", stdout);
//     #endif 
// }
 
lli power(lli a , lli n)
{
	lli result = 1;
 
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
 
		n >>= 1;
		a = (a * a) % mod;
	}
 
	return result;
}
 
 
void init(string input_string)
{
	lli p = 31;
	lli p_power = 1;
	dp[0] = (input_string[0] - 'a' + 1); 
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i]; 
		p_power = (p_power * p) % mod; 
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}
 
lli getHash(string key)
{
	lli value = 0;
	lli p = 31;
	lli p_power = 1;
 
	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	} 
	return value;
}
 
lli substringHash(int L , int R)
{
	int result = dp[R];
 
	if(L > 0) result = (result - dp[L-1] + mod) % mod;
 
	return result;
}
 
int main()
{	
	//init_code();
	//cout<<"helo";
	string haystack , needle;
	int n , L , R , answer;
	bool flag = false;
 
	while(cin>>n)
	{
		cin>>needle;
		cin>>haystack;
        if(n>haystack.size()){
            cout<<endl;
            continue;
        }
		lli needleHash = getHash(needle);
 
		init(haystack);
 		int kk=0;
		for(lli i=0;i<=(haystack.size()-n);i++){
			lli j=i+n-1;
            //cout<<"ho"<<endl;
            lli temp=(needleHash*power(31,kk)+mod)%mod;
			if(substringHash(i,j)==temp)
				cout<<i<<endl;
			kk++;
		}
 
		cout<<endl;
	}
}