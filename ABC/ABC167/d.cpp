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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, K;
    cin >> N >> K;
    vvll g(N);
    rep(i, N) {
        ll a;
        cin >> a;
        a--;
        g[i].push_back(a);
    }

    vector<bool> check(N, false);
    queue<ll> que;
    que.push(0);
    bool end = false;
    vll dist(N, 0);
    dist[0] = 0;
    ll loop = -1, cnt = 0;

    while((!que.empty()) && (!end)) {
        ll now = que.front();
        que.pop();
        check[now] = true;

        for(auto next : g[now]) {
            cnt++;
            if(check[next]) {
                end = true;
                loop = next;
                continue;
            }
            que.push(next);
            dist[next] = dist[now] + 1;
        }
    }

    debug(loop)
    debug(cnt)

    ll ans = -1;
    if(K <= dist[loop]) {
        rep(i, N) if(dist[i] == K) ans = i+1;
        cout << ans << endl;
        return 0;
    }

    ll res = (K - dist[loop]) % (cnt - dist[loop]);
    debug(res)

    ans = loop;
    rep(i, res) {
        ans = g[ans][0];
    }
    cout << ans + 1 << endl;
}
