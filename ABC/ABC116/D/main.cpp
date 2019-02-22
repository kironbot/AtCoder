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
typedef long long ll;
const long long INF = 1LL<<40;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> maxd(n, -INF), vals;
    multiset<ll> se;
    for (ll i = 0; i < n; i++) {
        ll s, v;
        cin >> s >> v;
        s--;
        chmax(maxd[s], v);
        vals.push_back(v);
    }
    sort(vals.begin(), vals.end(), greater<ll>());
    sort(maxd.begin(), maxd.end(), greater<ll>());
    ll sum = 0;
    for (ll i = 0; i < k; i++) sum += vals[i], se.insert(vals[i]);

    ll ans = 0, tmp = sum;
    for (ll x = 1; x <= k; x++) {
        ll add = maxd[x-1];
        ll back = *se.begin();
        tmp += add;
        if (back > add) {
            se.erase(se.begin());    
            tmp -= back;
        } else {
            se.erase(se.find(add));
            tmp -= add;
        }
        chmax(ans, tmp + x * x);
    }
    cout << ans << endl;
}
