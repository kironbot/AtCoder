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
    double ans = 0;
    rep(i, n) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") ans += x;
        else ans += x * 380000.0;
    }
    cout.precision(20);
    cout << ans << endl;
}
