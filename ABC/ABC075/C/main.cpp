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
ll a[100], b[100];
bool g[100][100];
bool visited[100];

void dfs(ll v) {
    visited[v] = true;
    rep(u, n) {
        if (g[v][u] == false || visited[u] == true) continue;
        dfs(u);
    }
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    }

    ll ans = 0;
    rep(i, m) {
        g[a[i]][b[i]] = g[b[i]][a[i]] = false;
        rep(j, n) visited[j] = false;

        dfs(0);
        
        bool bridge = false;
        rep(j, n) if (visited[j] == false) bridge = true;
        if (bridge) ans += 1;

        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    }
    cout << ans << endl;
}
