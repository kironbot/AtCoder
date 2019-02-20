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
    string s, t;
    cin >> s >> t;
    int ans = 2 * n;
    rep(i, n) {
        if (s.substr(i, n-i) == t.substr(0, n-i)) {
            ans = 2 * n - (n - i);
            break;
        }
    }
    cout << ans << endl;
}
