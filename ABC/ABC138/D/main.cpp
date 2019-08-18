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
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> g(n);    
    rep(i, 0, n-1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);        
        g[b].push_back(a);
    }
    vector<ll> x(n, 0);
    rep(i, 0, q) {
        ll p, y;
        cin >> p >> y;
        p--;
        x[p] += y;
    }

    vector<bool> ok(n, false);
    ok[0] = true;
    queue<ll> que;
    que.push(0);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();

        for(auto nv : g[v]) {
            if (ok[nv] == true) continue;

            ok[nv] = true;
            x[nv] += x[v];
            que.push(nv);
        }
    }

    rep(i, 0, n) cout << x[i] << " ";
    cout << endl;
}
