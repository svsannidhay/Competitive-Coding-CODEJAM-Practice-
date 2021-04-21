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

vector<ll> merge(vector<ll> &arr1,vector<ll> &arr2) {
    vector<ll> result;
    ll i = 0;
    ll j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            result.pb(arr1[i]);
            i++;
        } else {
            result.pb(arr2[j]);
            j++;
        }  
    }
    while(i < arr1.size()) {
        result.pb(arr1[i]);
        i++;
    }
    while(j < arr2.size()) {
        result.pb(arr2[j]);
        j++;
    }
    return result;
}

void buildSegmentTree(vector<ll> segTree[],vector<ll> &arr,ll si,ll ss,ll se) {
    if(ss > se) return;
    if(ss == se) {
        segTree[si].pb(arr[ss]);
        return;
    }
    ll mid = (ss + se) / 2;
    buildSegmentTree(segTree,arr,2 * si,ss,mid);
    buildSegmentTree(segTree,arr,2 * si + 1,mid + 1,se);
    
    segTree[si] = merge(segTree[2*si],segTree[2*si+1]);
    
}

//queries must be made on zero indexed array 
ll querySegmentTree(vector<ll> segTree[],ll si,ll ss,ll se,ll l,ll r,ll k) {
    // No Overlap
    if(ss > r || se < l) {
        return 0;
    }
    // Full Overlap
    if(ss >=l && se <= r) {
        ll res = upper_bound(segTree[si].begin(),segTree[si].end(),k - 1) - segTree[si].begin();
        return segTree[si].size() - (res);
    }
    ll mid = (ss + se) / 2;
    ll left = querySegmentTree(segTree,2*si,ss,mid,l,r,k);
    ll right = querySegmentTree(segTree,2*si+1,mid+1,se,l,r,k);
    return left + right;
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
    vector<ll> arr;
    vector<ll> segTree[4*n+1];
    for(ll i=0;i<n;i++) {
        cinll(x);
        arr.pb(x);
    }
    buildSegmentTree(segTree,arr,1,0,n-1);
    // for(ll i=0;i<4*n+1;i++) {
    //     for(ll j=0;j<segTree[i].size();j++) cout<<segTree[i][j]<<" ";
    //     cout<<"\n";
    // }

    while(q--) {
        cinll(l);cinll(r);cinll(k);
        cout<<querySegmentTree(segTree,1,0,n-1,l-1,r-1,k);
    }
  return 0;
}