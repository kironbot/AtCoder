#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll t, n, m;
    cin >> t >> n;
    vll a(n);
    rep(i,n) cin >> a[i];
    cin >> m;
    vll b(m);
    rep(i,m) cin >> b[i];

    if(n < m) {
        cout << "no" << endl;
        return 0;
    }

    bool ok = true;
    ll now = 0;
    rep(i,m) {
        while(now < n && !(a[now] <= b[i] && b[i] <= a[now] + t)) now++;
        if(now == n) ok = false;
        now++;
    }
    if(ok) cout << "yes" << endl;
    else cout << "no" << endl;
}
