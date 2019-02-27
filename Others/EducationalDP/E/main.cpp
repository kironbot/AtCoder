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

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    ll dp[110][100100];
    rep(i, 110) rep(j, 100100) dp[i][j] = 1LL << 60; 
    dp[0][0] = 0;
    rep(i, N) {
        rep(sum_v, 100100) {
            if (sum_v - v[i] >= 0) chmin(dp[i+1][sum_v], dp[i][sum_v - v[i]] + w[i]);
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }
    ll res = 0;
    rep(sum_v, 100100) if (dp[N][sum_v] <=W) res = sum_v;

    cout << res << endl;
}