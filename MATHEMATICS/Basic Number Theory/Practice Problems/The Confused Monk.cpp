//https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-confused-monk/
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
///////////////////////////////////////////////////////////////////////////////////////////////////
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define cinll(x) \
    ll x;        \
    cin >> x;
#define cini(x) \
    int x;      \
    cin >> x;
#define cins(x) \
    string x;   \
    cin >> x;
#define vect(x) vector<ll> x;
#define vect1(x)  \
    vector<ll> x; \
    x.push_back(0);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX 1e18
#define MIN -1000000007
#define MOD 1000000007
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////BINARY EXPONENTIATION/////////////////////////////////////////
ll binaryExponentiation(ll base, ll exp, ll mod)
{
    ll value = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            value = ((value % mod) * (base % mod)) % mod;
        exp /= 2;
        base = (base % mod * base % mod) % mod;
    }
    return value;
}
//Time complexity: O(log N)
/////////////////////////////////////FAST EXPONENTIATION///////////////////////////////////////////
ll fastExponentiation(ll base, ll exp, ll mod)
{
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base % mod;
    else
    {
        ll r = fastExponentiation(base, exp / 2, mod);
        if (exp % 2 == 0)
        {
            return ((r % mod) * (r % mod)) % mod;
        }
        else
        {
            return ((((r % mod) * (r % mod)) % mod) * (base % mod)) % mod;
        }
    }
}
//Time complexity: O(log N)
/////////////////////////////////////EUCLID's ALGORITHM/////////////////////////////////////////////
ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
//The time complexity is O(log(max(A, B))).
//////////////////////////////EXTENDED EUCLID's ALGORITHM////////////////////////////////////////////
void extendedEuclid(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(b, a % b, d, x, y);
        ll temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}
//The time complexity of the extended Euclidean algorithm is O(log(max(A, B))).
//////////////////////////////MODULAR MULTIPLICATIVE INVERSE/////////////////////////////////////////
//NAIVE APPROACH
ll modInverse(ll a, ll m)
{
    a = a % m;
    for (ll b = 1; b < m; b++)
    {
        ll val = (a * b) % m;
        if (val == 1)
            return b;
    }
    return -1; //MMI doesn't exists.
}
//Time complexity O(M)
//USING EXTENDED EUCLID'S
ll modInverseEEA(ll a, ll m, ll &d, ll &x, ll &y)
{
    extendedEuclid(a, m, d, x, y);
    return (x % m + m) % m; //x may be negative
}
//WHEN M is PRIME USE : - BINARY EXPONENTIATION
// Fermat's Little Theorem. (A^(M-1)) = 1 mod M;
// Multiplying b/s by A^-1
// A^(M-2)MOD M = A^-1
ll modInverseBE(ll a, ll m)
{
    return binaryExponentiation(a, m - 2, m);
}

//Time complexity O(log(max(A, B))).

/////////////////////////////////////////////////////////////////////////////////////////////////////
//SOLVE HERE
ll calgx(vector<ll> &arr, ll n)
{
    ll gcd = arr[0];
    for (ll i = 1; i < n; i++)
    {
        gcd = GCD(gcd, arr[i]);
    }
    return gcd % MOD;
}

ll calfx(vector<ll> &arr, ll n)
{
    ll fx = 1;
    for (ll i = 0; i < n; i++)
    {
        fx = (fx % MOD * arr[i] % MOD) % MOD;
    }
    return fx;
}

int main()
{
    fio;
    ll d, x, y; // FOR EXTENDED EUCLID'S ALGORITHM
    cinll(n);
    vector<ll> arr;
    for (ll i = 0; i < n; i++)
    {
        cinll(x);
        arr.pb(x);
    }
    ll gx = calgx(arr, n);
    ll fx = calfx(arr, n);
    cout << fastExponentiation(fx, gx, MOD) % MOD;
    return 0;
}
