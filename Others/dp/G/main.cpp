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

ll n, m;
vector<vector<ll>> G;

ll dp[100100];
ll rec(ll v) {
    if (dp[v] != -1) return dp[v];

    ll res = 0;
    for (auto nv : G[v]) {
        chmax(res, rec(nv) + 1);
    }
    return dp[v] = res;
}

int main() {
    cin >> n >> m;
    G.assign(n, vector<ll>());
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }

    rep(v, n) dp[v] = -1;

    ll res = 0;
    rep(v, n) chmax(res, rec(v));
    cout << res << endl;
}
