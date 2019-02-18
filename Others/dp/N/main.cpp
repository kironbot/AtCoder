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
ll s[410] = {};
ll dp[410][410];

ll rec(ll l, ll r) {
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    ll res = 1LL << 60;
    for (ll i = l+1; i <= r; i++) {
        chmin(res, rec(l, i-1) + rec(i, r) + s[r] - s[l-1]);
    }
    return dp[l][r] = res;
}

int main() {
    cin >> n;
    rep(i, n) {
        ll tmp;
        cin >> tmp;
        s[i+1] = s[i] + tmp;
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(1, n) << endl;
}