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
    vector<int> l(2*n);
    rep(i, 2*n) cin >> l[i];
    sort(l.begin(), l.end());
    ll ans = 0;
    rep(i, 2*n) {
        if (i % 2 == 0) ans += l[i];
    }
    cout << ans << endl;
}
