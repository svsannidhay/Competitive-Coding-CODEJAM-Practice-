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
#define MOD 1000000007
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
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
ll LSSB(ll x)
{
  return (x & (-x));
}

int main()
{
  fio;
  ///////////////////////////////////////////
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ///////////////////////////////////////////
  return 0;
}