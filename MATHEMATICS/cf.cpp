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
#include <chrono>

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
using u64 = uint64_t;
//Safe_hashing for minimising collisions 
//https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool comparex(pair<ll,ll> a,pair<ll,ll> b) {
  return a.first<b.first;
}
bool comparey(pair<ll,ll> a,pair<ll,ll> b) {
  return a.second<b.second;
}

map<pair<ll,ll>,int> mapit;

ll query(ll l,ll r) {
  if(mapit[mp(l,r)]!=0) return mapit[mp(l,r)];
  if(l==r) return -1;
  cout<<"? " << l << " " << r<<endl;
  cinll(x);
  mapit[mp(l,r)] = x;
  return x;
}

void answer(ll x) {
  cout<<"! "<<x<<endl;
}

int main(){
  cinll(n);
  ll l = 1;
  ll r = n;
  ll smax = query(l,r);
  ll ans;
  if(query(l,smax)==smax) {
    //On the left ; Find the maximum m such that query(m,smax) == smax;
    ll left = l;
    ll right = smax-1;
    ans = left;
    while(right>=left) {
      ll mid = (left + right) / 2;
      if(query(mid,smax)==smax) {
        left = mid + 1;
        ans = mid;
      } else {
        right = mid-1;
      }
    }
  }else { 
    //On the right ; Find the minimum m such that query(smax,m) == smax;
    ll left = smax+1;
    ll right =  r;
    ans = right;
    while(right>=left) {
      ll mid = (left + right)/2;
      if(mid>smax&&query(smax,mid)==smax) {
        right = mid - 1;
        ans = mid;
      }else{
        left = mid + 1;
      }
    }
  }
  answer(ans);
  return 0;
}