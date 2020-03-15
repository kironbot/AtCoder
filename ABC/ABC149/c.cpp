#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) return false;
    }
    return true;
}

int main() {
    ll x;
    cin >> x;
    while(true) {
        if(is_prime(x)) {
            cout << x << endl;
            return 0;
        }
        else x++;
    }
}
