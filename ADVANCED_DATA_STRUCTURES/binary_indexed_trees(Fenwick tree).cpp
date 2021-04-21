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
#define MAX 9223372036854775807
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

//Finding the Least significant set bit value 
//like LSSB(1000 binary) = 8 { 2^3 }
// LSSB(4) = 4 { 2^2 } 
// LSSB(x) = x & (-x)
/*
    Say x = a1b (in bianry) where b contains all zeros 
    x' = a'0b' + 1 = a'0(1...1) + 1 = a'1(0....0) = a'1b 
    =>  a1b
       &a'1b
    = (0..0)1(0...0)
*/
ll LSSB(ll x) {
    return (x & (-x));
}

//////////////////////////////BINARY INDEXED TREE (FENWICK TREE) ///////////////////////////

void update (vector<ll> &BIT,ll ind,ll val) {
    for(ll i = ind;i <= BIT.size(); i += LSSB(i) ) {
        BIT[i] += val;
    }
}

//Return the result of query from 1 to x;
ll query (vector<ll> &BIT,ll x) {
    ll sum = 0;
    for(ll i = x;i >= 1;i -= LSSB(i)) {
        sum += BIT[i];
    }
    return sum;
}


int main(){
    fio;
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
///////////////////////////////////////////
    cinll(n);cinll(q);
    vector<ll> BIT(n+1,0);
    vector<ll> arr(n+1,0); 
    for(ll i=0;i<n;i++) {
        cinll(x);
        arr[i+1] = x; 
        update(BIT,i+1,x);
    }
    while(q--) {
        char ch;cin>>ch;
        if(ch == 'q') {
            cinll(l);cinll(r);
            cout<<query(BIT,r) - query(BIT,l-1) <<"\n";
        } else {
            cinll(ind);cinll(val);
            update(BIT,ind,-1 * arr[ind]);
            arr[ind] = val;
            update(BIT,ind,val);
        }
    }
  return 0;
}