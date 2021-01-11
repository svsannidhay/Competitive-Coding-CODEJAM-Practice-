////https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/panda-and-chain-reaction/description/?layout=old
///////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<climits>
#include<set>
#include<cstring>
#include<unordered_map>
#include<cstdlib> 
#include<cmath>
#include<string>
#include<iomanip>
#include<cmath>
///////////////////////////////////////////////////////////////////////////////////////////////////
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll            long long int
#define ull           unsigned long long int
#define cinll(x)      ll x;cin>>x;
#define cini(x)       int x;cin>>x;
#define cins(x)       string x;cin>>x;
#define vect(x)       vector<ll> x;
#define vect1(x)      vector<ll> x;x.push_back(0);
#define pb(x)         push_back(x)
#define mp(x,y)       make_pair(x,y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX           1e18
#define MIN           -1000000007
#define MOD           1000000007
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////
ll factt[1000006];
void factorial(ll n,ll mod){
	ll fact = 1;
	factt[0] = 1;
	factt[1] = 1;
	for(ll i=2;i<=n;i++){
		fact = ( (fact % mod) * (i % mod) )%mod;
		factt[i] = fact;
 	}
}

int main(){
	cinll(t);
	factorial(1000002,1000003);
	while(t--){
		cinll(n);cinll(x);
		if(n<1000003)	cout<<(x%1000003 * factt[n]%1000003 ) % 1000003<<"\n";
		else cout<<0<<"\n";
	}
    return 0;
}