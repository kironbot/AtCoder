#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n;
    cin >> n;
    vll c(n);
    rep(i, n) cin >> c[i];

    stack<pll> stk;

    for(ll i = 0; i < n; i++) {
        if (i == 0) stk.emplace(c[i], 1);
        else if (i % 2 == 0) {
            ll t = stk.top().first;
            if(t == c[i]) {
                ll k = stk.top().second;
                stk.pop();
                stk.emplace(c[i], k + 1);
            }
            else stk.emplace(c[i], 1);
        }
        else {
            ll k = stk.top().second;
            stk.pop();
            ll k2 = 0;
            if(!stk.empty() && stk.top().first == c[i]) k2 += stk.top().second, stk.pop();
            stk.emplace(c[i], k + k2 + 1);
        }
    }

    ll ans = 0;
    while(!stk.empty()) {
        if(stk.top().first == 0) ans += stk.top().second;
        stk.pop();
    }
    cout << ans << endl;
}
