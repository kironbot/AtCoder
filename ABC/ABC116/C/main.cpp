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
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll ans=0;
    while(true){
        if(*max_element(h.begin(), h.end()) == 0) break;
        rep(i, n) {
            if(h[i]==0) continue;
            for(ll j=i; j<n; j++) {
                if(h[j]==0) break;
                h[j]--;
            }
            break;
        }
        ans++;
    }
    cout << ans << endl;
}
