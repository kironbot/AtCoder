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
    ll k, a, b;
    cin >> k >> a >> b;
    if (b - a <= 2) {
        cout << k + 1 << endl;
        return 0;
    }

    ll ans=1;
    for (ll i = 0; i < k; i++) {
        if (k - i >= 2 && ans >= a) {
            ans += b - a;
            i++; 
        }
        else {
            ans++;
        }
    }
    cout << ans << endl;
}
