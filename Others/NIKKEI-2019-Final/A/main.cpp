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
    ll n;
    cin >> n;
    vector<ll> sum(n+1, 0);
    rep(i, n) {
        ll a;
        cin >> a;
        sum[i+1] = sum[i] + a;
    }
    for (int k = 1; k <= n; k++) {
        ll ans = 0;
        rep(i, n-k+1) chmax(ans, sum[i+k] - sum[i]);
        cout << ans << endl;
    }
}
