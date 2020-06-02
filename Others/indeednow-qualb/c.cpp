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

    ll N; cin >> N;
    vvll g(N+1);
    rep(i, N-1) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> visit(N+1, false);
    vll ans;
    priority_queue<ll, vll, greater<ll>> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty()) {
        ll now = q.top();
        q.pop();
        visit[now] = true;
        ans.push_back(now);

        for(auto to : g[now]) {
            if(visit[to]) continue;
            q.push(to);
        }
    }
    rep(i, N) {
        if(i < N-1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}
