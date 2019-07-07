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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> g(n);
    rep(i, 0, n-1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b); 
        g[b].push_back(a); 
    }

    vector<ll> seen(n, 0);
    queue<ll> que;
    seen[0] = 1;
    que.push(0);
    ll ans = k, cnt = 1;
    while(!que.empty()) {
        ll v = que.front();
        que.pop();

        for(auto nv : g[v]) {
            if (seen[nv] == 1) continue;
            seen[nv] = 1;
            ans *= max(0LL, (k-cnt));
            ans %= MOD;
            cnt++;
            que.push(nv);
        }
        cnt = 2;
    }
    cout << ans % MOD << endl;
}
