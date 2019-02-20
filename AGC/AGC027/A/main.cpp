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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, n) {
        if (x >= a[i]) {
            ans++;
            x -= a[i];
        }
        else {
            x -= a[i];
            break;
        }
    }
    if (x > 0) ans--;
    cout << ans << endl;
}
