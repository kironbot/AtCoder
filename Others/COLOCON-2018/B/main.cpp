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
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int ans = 0;
    rep(i, n) {
        int t;
        cin >> t;
        if (s[i] == '0') ans += t;
        else ans += min(t, x);
    }
    cout << ans << endl;
}
