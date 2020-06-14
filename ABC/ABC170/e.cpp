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

    ll N, Q;
    cin >> N >> Q;
    vector<multiset<ll>> vec(210000);
    vll en(N), a(N), b(N);
    rep(i, N) {
        cin >> a[i] >> b[i];
        vec[b[i]].insert(a[i]);
    }

    multiset<ll> se;
    rep(i, 210000) {
        if(!vec[i].empty()) {
            auto it = vec[i].rbegin();
            se.insert(*it);
        }
    }

    rep(i, Q) {
        ll c, d;
        cin >> c >> d;
        c--;
        ll x, now;
        x = a[c];
        now = b[c];

        se.erase(se.find(*vec[now].rbegin()));
        vec[now].erase(vec[now].find(x));
        if(!vec[now].empty()) se.insert(*vec[now].rbegin());

        if(!vec[d].empty()) se.erase(se.find(*vec[d].rbegin()));
        vec[d].insert(x);
        se.insert(*vec[d].rbegin());

        b[c] = d;

        cout << *se.begin() << endl;
    }
}
