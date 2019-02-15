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
    ll n, k;
    cin >> n >> k;
    ll a[110]; 
    rep(i, n) cin >> a[i];
    ll dp[100100];
    rep(j, k+1) {
        ll lose=0, cnt=0;
        rep(i, n) {
            if (j - a[i] >= 0) {
                cnt++;
                if(dp[j - a[i]] == 0) lose++;
            }
        }
        if (cnt == 0 || lose == 0) dp[j] = 0;
        else dp[j] = 1;
    }

    if (dp[k] == 1) cout << "First" << endl;
    else cout << "Second" << endl;
}
