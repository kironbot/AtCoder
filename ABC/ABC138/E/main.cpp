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
    string s, t;
    cin >> s >> t;
    ll ns = (ll)s.size(), nt = (ll)t.size();

    vector<vector<ll>> idx(26);
    rep(i, 0, ns) idx[s[i] - 'a'].push_back(i);
    rep(i, 0, ns) idx[s[i] - 'a'].push_back(ns+i);
    
    ll ans = 0, p = 0;
    rep(i, 0, nt) {
        ll c = t[i] - 'a';
        if(idx[c].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        p = *lower_bound(idx[c].begin(), idx[c].end(), p) + 1;
        if (p >= ns) {
            p -= ns;
            ans += ns;
        }
    }
    ans += p;
    cout << ans << endl;
}
