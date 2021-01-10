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

vector< vector<ll> > matrixMultiplication(vector< vector<ll> > a,vector< vector<ll> > b){
    vector< vector<ll> > c(a[0].size());
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<b[0].size();j++){
            ll val = 0;
            for(ll k=0;k<a[0].size();k++){
                val += a[i][k] * b[k][j];
            }
            c[i].pb(val);
        }
    }
    return c;
}