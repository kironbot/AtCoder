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

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

int main() {
    ll n, ans;
    cin >> n;
    rep(i, n) {
        ll a;
        cin >> a;
        if (i == 0) ans = a;
        else ans = gcd(a, ans);
    }
    cout << ans << endl;
}
