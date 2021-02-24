///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <climits>
#include <set>
#include <cstring>
#include <unordered_map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <stdlib.h>
#include <boost/multiprecision/cpp_int.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
#define fio  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin >> x;
#define cini(x) int x;cin >> x;
#define cins(x) string x;cin >> x;
#define vect(x) vector<ll> x
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX 1e18
#define MIN -1000000007
#define MOD 1000000007
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::multiprecision;
using u64 = uint64_t;
using u128 = __uint128_t;
/////////////////////////////////////BINARY EXPONENTIATION FOR 128 bit number/////////////////////////////////////////
ll binPower(ll base,ll exp,ll mod) {
  ll result = 1;
  base%mod;
  while(exp) {
    if(exp & 1) result = (((u128)result %mod) * (base % mod)) % mod;
    base = (((u128)base%mod) * (base%mod) ) %mod;
    exp>>=1;
  }
  return result;
}
////////////////////////////FERMAT's PRIMALITY TEST///////////////////////////////
bool probablyPrimeFermat (ll n) {
  if(n <= 4) return n == 2 || n == 3;
  for(ll i=0;i<log(n);i++) {
    ll a = 2 + (rand() % (n-3));
    ll res = binPower(a,n-1,n);
    if (res!=1) return false;
  }
  return true;
}
//Complexity : log(n)
////////////////////////////MILLER RABIN TEST /////////////////////////////////
bool check_composite(ll n,ll a,ll d,ll s) {
  ll x = binPower(a,d,n);
  if (x == 1 || x == n-1) return false;
  for(ll r=1;r<s;r++) {
    x = ( ((u128)x%n) * (x%n) ) % n;
    if(x == n-1) return false;
  }
  return true;
}

bool MillerRabin(ll n) {
  if(n <=4 ) return n==2 || n==3;
  ll s = 0;
  ll d = n-1;
  while((d&1)==0) {
    d >>= 1;
    s++;
  }
  for(ll i=0 ;i<log(n);i++) {
    ll a = 2 + (rand() % (n-3));
    if(check_composite(n,a,d,s)) return false;
  }
  return true;
}
//If you want it to be deterministic till 64 bit integer what we can do is
//instead of choosing a randomly check for 2 3 5 7 11 13 17 19 23 29 31 37

int main () {
  cinll(t);
  while (t--) {
    cinll(n);
    if(MillerRabin(n)) cout<<"prime\n";
    else cout<<"composite\n";
  }
  return 0;
}