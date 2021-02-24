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

//SEGMENT TREE FOR MIN RANGE QUERUES AND POINT UPDATES
//Segement tree is indexed from 1 
void buildSegmentTree (vector<ll> &segTree,vector<ll> &arr,ll index,ll start,ll end) {
    if(start>end) return;
    //Base case : - LEAF NODE
    if(start==end) {
        segTree[index] = arr[start];
        return;
    }
    ll mid = (start + end) / 2; 
    buildSegmentTree(segTree,arr,2*index,start,mid);
    buildSegmentTree(segTree,arr,2*index+1,mid+1,end);
    ll left = segTree[2*index];
    ll right = segTree[2*index+1];

    segTree[index] = min(left,right);
}
//queries must be on zero indexed array
ll querySegmentTree (vector<ll> &segTree,ll index,ll start,ll end,ll l,ll r) {
    //Case 1 No overlap 
    if(l>end||r<start) {
        return MAX;
    }
    // Case 2 Complete Overlap 
    if(start>=l&&end<=r) {
        return segTree[index];
    }
    //Case 3 Partial overlap 
    ll mid = ( start + end ) / 2;
    ll leftNode =  querySegmentTree(segTree,2*index,start,mid,l,r);
    ll rightNode = querySegmentTree(segTree,2*index+1,mid+1,end,l,r);
    return min(leftNode,rightNode);
}
//Node Updates in a segment tree
void updateaSegmentTree (vector<ll> &segTree,vector<ll> &arr,ll treeIndex,ll start,ll end,ll ind,ll val) {
    if(start==end) {
        arr[ind] = val;
        segTree[treeIndex] = val;
        return;
    } 
    ll mid = ( start + end ) / 2;
    if(start<=ind&&ind<=mid) {
        updateaSegmentTree(segTree,arr,treeIndex*2,start,mid,ind,val);
    } else {
        updateaSegmentTree(segTree,arr,treeIndex*2+1,mid+1,end,ind,val);
    }
    segTree[treeIndex] = min(segTree[2*treeIndex],segTree[2*treeIndex+1]);
    return;
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
    for(ll i=0;i<n;i++) {
        cinll(x);
        arr.pb(x);
    }
    vector<ll> segTree(4*n+1,0);
    buildSegmentTree(segTree,arr,1,0,n-1);
    // for(ll i=0;i<segTree.size();i++) cout<<segTree[i]<<" "; 
    while(q--) {
        cinll(l); cinll(r);
        l--;r--;
        cout<<querySegmentTree(segTree,1,0,n-1,l,r)<<"\n";
    }
  return 0;
}