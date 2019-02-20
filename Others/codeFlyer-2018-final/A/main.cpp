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
    ll ans = 1LL<<30;
    rep(i, n) {
        ll p;
        cin >> p;
        ll tmp = 0;
        while(p > 0) {
            if (p % 10 == 0) tmp++;
            else break;
            p /= 10;
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
