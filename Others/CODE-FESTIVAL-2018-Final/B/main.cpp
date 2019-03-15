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
    ll n, m;
    cin >> n >> m;
    double logfact[110000];
    memset(logfact, 0, sizeof(logfact));
    rep(i, 0, n) logfact[i+1] = logfact[i] + log10(i+1);
    double logsum = n*log10(m) - logfact[n];
    rep(i, 0, m) {
        ll r;
        cin >> r;
        logsum += logfact[r];
    }
    cout << (ll)logsum + 1 << endl;
}
