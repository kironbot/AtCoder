#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll n;
vector<ll> g[100000];
ll dp[100000][2];
ll MOD = 1e9 + 7;

void dfs(ll idx, ll par) {
    ll latte = 1, malta = 1;
    for(auto &to : g[idx]) {
        if (to == par) continue;
        dfs(to, idx);
        (latte *= (dp[to][0] + dp[to][1]) % MOD) %= MOD;
        (malta *= dp[to][0]) %= MOD;
    }
    dp[idx][0] = latte;
    dp[idx][1] = malta;
}
int main() {
    cin >> n;
    rep(i, n-1) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]) % MOD << endl;
}
