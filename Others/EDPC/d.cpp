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

    ll dp[110][100100] = {0};
    rep(i, N) {
        rep(j, W + 1) {
            if (j - w[i] >= 0) chmax(dp[i+1][j], dp[i][j - w[i]] + v[i]);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    cout << dp[N][W] << endl;
}