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

/////////////////////////////////////BINARY EXPONENTIATION/////////////////////////////////////////
ll binaryexponential(ll base, ll exp, ll mod){
    ll value = 1;
    while(exp>0){
        if(exp%2==1)
            value = ((value % mod) * (base % mod)) % mod;
        exp/=2;
        base = (base%mod * base%mod)%mod;
    }
    return value;
}

/////////////////////////////////////FAST EXPONENTIATION///////////////////////////////////////////
ll fastexponential(ll base,ll exp,ll mod){
    if(exp==0)  return 1;
    else if(exp==1) return base%mod;
    else{
        ll r = fastexponential(base,exp/2,mod);
        if(exp%2==0){
            return ( (r%mod) * (r%mod) )%mod;
        }else{
            return ( ( ( (r%mod)*(r%mod) )%mod ) * (base%mod)  )%mod;
        }
    }
}

int main(){
    cout<<binaryexponential(5,4,MOD);
    return 0;
}