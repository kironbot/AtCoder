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
    int n;
    cin >> n;
    int amin = 100, amax = -100;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        chmin(amin, a[i]);
        chmax(amax, a[i]);
    }
    ll ans = 1LL<<60;
    for (int m = amin; m <= amax; m++) {
        ll tmp = 0;
        rep(i, n) tmp += (m - a[i]) * (m - a[i]);
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
