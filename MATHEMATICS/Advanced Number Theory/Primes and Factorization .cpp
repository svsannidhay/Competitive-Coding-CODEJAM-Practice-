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
///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////SIEVE OF ERATOSTHENES /////////////////////////////////////////////////
vector<ll> sieveOfEratosThenes(ll n){
    vector<ll> prime(n+1,1);
    vector<ll> primeNumbers;
    for(ll i=2;i<=n;i++){
        if(prime[i]==1){
            primeNumbers.pb(i);
            for(ll j=i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    return primeNumbers;
}
//Complexity :- O(N log(log(N)))   //Works Upto (10^7)
////////////////////////////BITSET SIEVE OF ERATOSTHENES /////////////////////////////////////////
vector<ll> bitsetSieveOfEratosThenes(ll n){
    bitset<10000000> b;
    b.set();
    vector<ll> primeNumbers;
    for(ll i=2;i<=n;i++){
        if(b[i]==1){
            primeNumbers.pb(i);
            for(ll j=i*i;j<=n;j+=i){
                b[j] = 0;
            }
        }
    }
    return primeNumbers;
}
//Complexity :- O(N log(log(N)))   //Works Upto (8*10^7)
////////////////////// SEGMENTED SIEVE OF ERATOSTHENES ///////////////////////////////////////////

vector<ll> segmentedSieve(ll m,ll n){
    if(m==1) m++;
    vector<ll> primes = sieveOfEratosThenes(sqrt(n+1));
    vector<bool> segment(n-m+1,true);
    for(ll i=0;i<primes.size();i++){
        if(primes[i]*primes[i]>n) break;
        ll start = m;
        if(m%primes[i]!=0){
            start += (primes[i] - (start%primes[i]));
        }
        ll ind = start-m;
        for(ll j = ind;j<segment.size();j+=primes[i]){
            if(j+m!=primes[i]) segment[j] = false;
        }
    }
    vector<ll> primesnm;
    for(ll i=0;i<segment.size();i++){
        if(segment[i]) primesnm.pb(i+m);
    }
    return primesnm;
}

////////////////////////////PRIME FACTORIZATION (Precomputed primes)//////////////////////////////
//https://cp-algorithms.com/algebra/factorization.html
//Takes prime numbers Upto Sqrt(N) and generates Prime factorization as a map<prime,frequency>
unordered_map<ll,ll> primeFactorization(vector<ll> &primes,ll n){
	unordered_map<ll,ll> mapit;
	for(ll i=0;i<primes.size();i++){
		ll count = 0;
		while(n%primes[i]==0){
			n/=primes[i];
			count++;
		}
		if(count>0) mapit[primes[i]] = count;
		if(primes[i]*primes[i]>n) break;
	}

	if(n>1) mapit[n] = 1;
    return mapit;
}
//Total number of factors of a number with prime factorization a^p * b^q * c^r are (p+1).(q+1).(r+1)
//Complexity  :- O( (Primes upto sqrt(N)) * log(n) )  //Works Upto (10^12)

//////////////////////////////////Euler totient function //////////////////////////////////////////
// value of totient fucntion phi(n) is equal to no of numbers coprime with n which are less than n.
//ex phi(8) = 4 {1,3,5,7}
// if n = p1^x * p2^y *.....* pk^z then 
// according to Euler phi(n) = n*[1-1/p1]*[1-1/p2]*....*[1-1/pk] 

ll eulerTotientFunction(unordered_map<ll,ll> &primeFactors,ll n){
	ll phi = n;
	for(auto it=primeFactors.begin();it!=primeFactors.end();it++){
		phi /= it->first; // first divide then mult to prevent integer overflows
        phi *= (it->first - 1);
    }
	return phi;
}


////////////////////////SUM OF DIVISORS USING EULER'S RECURSION + DP ///////////////////
//http://numberworld.blogspot.com/2013/09/sum-of-divisors-function-eulers.html#:~:text=One%20could%20write%20the%20recursion,0%20%3C%20n%2Dp(%2Db_2)%24.
/*
    D(n) = D(n-1) + D(n-2) - D(n - 5) - D(n - 7) + D(n - 12) + D(n - 15) .......
    1 2 5 7 12 15 .... is the sequence of generalized pentagonal numbers (3𝑛2−𝑛)/2 for
    n = 1 -1 2 -2 ..... and the signs are repetitions of 1,1,−1,−1.
    base case D(0) = 0 for sum of proper diviors
    D(0) = n for sum of all divisors

    Complexity : O(N * Sqrt(N) ) for N numbers
*/
ll dp[10000001]; 

ll cal(ll n) {
    ll val = 3 * n * n;
    val -= n;
    val /= 2;
    return val; 
}

ll solvedp(ll n,ll &check) {
    check++;
    if(dp[n] != -1) return dp[n];
    ll start = 1;
    ll arr[4];
    arr[0] = 1;arr[1] = 1;
    arr[2] = -1;arr[3] = -1;
    ll count = 0;
    ll cnt = 0;
    dp[n] = 0;
    while(cal(start) <= n) {
        if(n - cal(start) == 0) {
            dp[n] += arr[cnt] * n;
        } else {
            dp[n] += arr[cnt] * solvedp(n-cal(start),check);
        }
        count++;
        cnt++;
        cnt = cnt % 4;
        if(count % 2 != 0) {
            start *= -1;
        } else {
            start *= -1;
            start++;
        }
    }
    return 0;
}


///////////////////////Sum and no of divisors of a number (Precomputed)/////////////////////////
/*
    Also what we can actually do is 
    iterate over from 1 to n;
    and keep adding i to all the multiples of i;
    ex add 3 to  3, 6, 9, 12 ....... 9999


    complexity :-  O(NlogN)
*/
ll sumdiv[10000005];
void solvedp() {
    for(ll i=1;i<=10000001;i++) {
        for(ll j=i;j<=10000001;j+=i) {
            sumdiv[j] += i;
        }
    }
}


int main(){
    vector<ll> primes = bitsetSieveOfEratosThenes(720);
    for(ll i=0;i<primes.size();i++) cout<<primes[i]<<" ";
    return 0;
}