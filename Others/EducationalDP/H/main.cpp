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

const ll mod = 1000000007;

ll h, w;
vector<string> a;

ll dp[1100][1100] = {};

void add (ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    cin >> h >> w;
    a.resize(h);
    rep(i, h) cin >> a[i];

    dp[0][0] = 1;
    rep(i, h) {
        rep(j, w) {
            if (i+1 < h && a[i+1][j] == '.') add(dp[i+1][j], dp[i][j]);
            if (j+1 < w && a[i][j+1] == '.') add(dp[i][j+1], dp[i][j]);
        }
    }
    cout << dp[h-1][w-1] << endl;
}