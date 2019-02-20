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
    string a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    rep(i, n) {
        if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) ans += 2;
        else if (a[i] != b[i] || b[i] != c[i] || c[i] != a[i]) ans += 1;
    }
    cout << ans << endl;
}
