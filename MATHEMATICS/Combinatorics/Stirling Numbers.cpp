/*
  Stirling Numbers of second kind
  S(n,k) : - No of ways to partition n objects into k similar boxes

  ex: S(5,3) : 
    Partition 5 objects into 3 boxes 

    1 2 3 4 5 
    box : 1 2 3
    box : 4          => 123/4/5
    box : 5 

    remeber 123/4/5 == 5/123/4 == 4/5/123 so we will count them as 1 

    123/4/5   12/34/5   14/35/2
    124/3/5   13/24/5   15/34/2
    125/3/4   14/23/5   23/45/1
    134/2/5   12/35/4   24/35/1
    135/2/4   13/25/4   
    145/2/3   15/23/4
    234/1/5   12/45/3
    235/1/4   14/25/3
    245/1/3   15/24/3
    345/1/2   13/45/2

    => S(5,3) = 25

    Base Cases : 
    S(0,0) = 1
    S(n,0) = 0 for n >= 1
    S(n,n) = 1
    S(n,1) = n
    S(n,n-1) = nC2

    S(n,k) = S(n-1,k-1) + K(S(n-1,k))

    S(5,3) = S(4,2) + 3S(4,3)
    S(4,2) = S(3,1) + 2S(3,2)
    S(3,1) = S(2,0) + 1S(2,1)
    S(3,1) = 0 + 1(S(1,0) + 1(S(1,1))) = 0 + 1(0 + 1) = 1
    => S(4,2) = 1 + 2S(3,2)
    eventually we can calculate it like this 



    Stirling Numbers of first kind 

    Signless Stirling numbers of the first kind 
    C(n,k) : no of ways to partition n numbers into k circles 

    C(5,2) 
    % objest 1 ,2 ,3 , 4, 5
    circle1 :     1
                3   2
                              =  (123) (45)
    circle2 :    4
                    5

    rotating tables will not change the arrangement 

    =>    1          4        ==     4            3
        3   2        5               5          2   1
        
    All possible arrangements 
    C(5,2) = 50 
    https://www.geeksforgeeks.org/calculate-stirling-numbers-which-represents-the-number-of-ways-to-arrange-r-objects-around-n-different-circles/

    recursive formula 
    C(n,k) = C(n-1,k-1) + (n-1)C(n-1,k)
    Base Cases : 
    C(0,0) = 1
    C(n,0) = 0 for n >= 1
    C(n,n) = 1
    C(n,1) = (n-1)!
    C(n,n-1) = nC2

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
#define fio                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define cinll(x) \
  ll x;          \
  cin >> x;
#define cini(x) \
  int x;        \
  cin >> x;
#define cins(x) \
  string x;     \
  cin >> x;
#define vect(x) vector<ll> x
#define vect1(x) \
  vector<ll> x;  \
  x.push_back(0);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX 9223372036854775807
#define MIN -1000000007
#define MOD 998244353
#define f first
#define s second
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using u64 = uint64_t;
//Safe_hashing for minimising collisions
//https://codeforces.com/blog/entry/62393
struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const
  {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

// Function to calculate the Signless Stirling numbers for first type.
//S(n,k) : no of ways to partition n numbers into k circles

ll dpFact[100005];
void calFac()
{
  dpFact[0] = 1;
  ll fac = 1;
  for (ll i = 1; i <= 100000; i++)
  {
    fac = ((fac % MOD) * (i % MOD)) % MOD;
    dpFact[i] = fac;
  }
  return;
}

ll dp[5000][5000];

ll stirlingNumber(ll n, ll k)
{
  if (dp[n][k] != -1)
    return dp[n][k];
  if (k > n)
    dp[n][k] = -1;
  else if (k == 0)
    dp[n][k] = 0;
  else if (k == n)
    dp[n][k] = 1;
  else if (k == 1)
    dp[n][k] = dpFact[n - 1];
  else if (n - k == 1)
    dp[n][k] = (n * (n - 1) / 2) % MOD;
  else
    dp[n][k] = ((stirlingNumber(n - 1, k - 1) % MOD) + ((((n - 1) % MOD) * (stirlingNumber(n - 1, k) % MOD)) % MOD)) % MOD;
  return dp[n][k];
}

ll solve()
{
  memset(dp, -1, sizeof(dp));
  cinll(n);
  for (ll i = 1; i <= n; i++)
  {
    cout << stirlingNumber(n, i) << " ";
  }
  return 0;
}

int main()
{
  fio;
  calFac();
  ///////////////////////////////////////////
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ///////////////////////////////////////////
  // cinll(t);
  // for(ll i=1;i<=t;i++) {
  solve();
  // }
  return 0;
}
