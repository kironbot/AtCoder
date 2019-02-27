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
    ll MOD = 1e9+7;
    ll H, W, K;
    cin >> H >> W >> K;
    K--; //0-indexedにする

    ll dp[H+1][W] = {};
    dp[0][0] = 1;

    rep(h, H) {
        for (int b = 0; b < (1<<(W-1)); b++) {
            // 横軸が隣り合っていないかチェック
            bool ok = true;
            rep(i, W-2) {
                // 末尾が11なら隣り合っている
                if ((b>>i) % 4 == 3) ok = false;
            }
            if(!ok) continue;

            // 各始点の終点を求める
            ll perm[W];
            rep(i, W) perm[i] = i;
            rep(i, W-1) {
                // あみだくじで位置をswap
                if ((b>>i) & 1) swap(perm[i], perm[i+1]);
            }

            // dp更新
            rep(i, W) {
                dp[h+1][perm[i]] += dp[h][i];
                dp[h+1][perm[i]] %= MOD;
            }
        }
    }
    cout << dp[H][K] << endl;
}
