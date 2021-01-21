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
    for(ll i=4;i<=n;i+=2){
        if((i&1)==0) prime[i] = 0;
    }
    for(ll i=3;i<=n;i++){
        if(prime[i]==1){
            for(ll j=i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    vector<ll> primeNumbers;
    for(ll i=2;i<=n;i++){
        if(prime[i]==1) primeNumbers.pb(i);
    }
    return primeNumbers;
}
//Complexity :- O(N log(log(N)))   //Works Upto (10^7)
////////////////////////////PRIME FACTORIZATION (Precomputed primes)//////////////////////////////
//https://cp-algorithms.com/algebra/factorization.html
//Takes prime numbers Upto Sqrt(N) and generates Prime factorization as a map<prime,frequency>
unordered_map<ll,ll> primeFactorization(vector<ll> primes,ll n){
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

int main(){
    cinll(n);
    vector<ll> primes = sieveOfEratosThenes(1000005);
    while(n--){
        cinll(x);
        unordered_map<ll,ll> mapit = primeFactorization(primes,x);
        if(mapit.size()>=3) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}