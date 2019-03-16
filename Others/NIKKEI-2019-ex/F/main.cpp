#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll x = 1789997546303;
    ll n;
    cin >> n;
    for(ll i = 1000; i > n; i--) {
        if (x % 2 == 0) x /= 2;
        else x = 3*x + 1;
    }
    cout << x << endl;
}