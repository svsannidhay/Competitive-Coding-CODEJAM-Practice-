/*
  Problem Statement 
  Berland shop sells 𝑛 kinds of juices. Each juice has its price 𝑐𝑖. Each juice includes some set of vitamins in it. There are three types of vitamins: vitamin "A", vitamin "B" and vitamin "C". Each juice can contain one, two or all three types of vitamins in it.

  Petya knows that he needs all three types of vitamins to stay healthy. What is the minimum total price of juices that Petya has to buy to obtain all three vitamins? Petya obtains some vitamin if he buys at least one juice containing it and drinks it.
  
  I/P
  4
  5 C
  6 B
  16 BAC
  4 A
  
  O/P
  15

  Approach : 

  So we need to define a state F(A,B,C) denoting whether A is present or not B is present or not C is present or not also A B C are mutually independent
  So,
  A -> 1,0
  B -> 1,0
  C -> 1,0
  => F(1,0,1) means A is present B is not C is present
  Instead of maintaining 3 variable we can combine them into a single variable 
  say F(X) so F(5) means 5 -> 101 means A is present B is not C is present
  Means 
  A -> 2^2
  B -> 2^1
  C -> 2^0
  And instead of F(A,B,C) we will use F(mask) This is called bitmasked DP 
  Where current state represents values for multiple boolean states

  F(n,mask) -> lowest cost that satisfies the mask and you have used only first n strings  

*/

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
#define ll  long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin >> x;
#define cini(x) int x;cin >> x;
#define cins(x) string x;cin >> x;
#define vect(x) vector<ll> x
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX 1e17
#define MIN -9223372036854775800
#define MOD 1000000007
#define f first
#define s second
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
 

struct custom_compare{
    bool operator()(pair< ll,pair<ll,ll> > a,pair< ll,pair<ll,ll> > b) {
        return a.f>b.f;
    }
};


/*
    
    A -> 2^2
    B -> 2^1
    C -> 2^0 

*/
void solve() {
    cinll(n);
    ll dp[n+1][9];
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<8;j++) {
            dp[i][j] = MAX;
        } 
    }
    dp[0][0] = 0;
    for(ll i=0;i<n;i++) {
        cinll(cost);cins(s);
        ll string_mask = 0;
        for(ll pos = 0;pos < 3;pos++) {
            char c = 'C' - pos;
            bool found = false;
            for(ll i=0;i<s.length();i++) {
                if(s[i] == c) found = true;
            }
            if(found) string_mask += (1 << pos);
        }
        for(ll mask=0;mask<8;mask++) {
            dp[i+1][mask] = min(dp[i+1][mask],dp[i][mask]);
            dp[i+1][mask | string_mask] = min(dp[i+1][mask | string_mask], dp[i][mask] + cost); 
        }            
    }
    ll ans = MAX;
    ans = dp[n][7];
    if(ans == MAX) ans = -1;
    cout<<ans;
}
 
 
int main(){
    // fio;
    // cinll(t);
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
///////////////////////////////////////////
    // cinll(t);
    // while(t--) {
        solve();
    // }
  return 0;
}