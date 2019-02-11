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
    string s, t;
    cin >> s >> t;
    ll ls = s.size(), lt = t.size();
    ll MAX = 3100;
    ll dp[MAX][MAX] = {0};
    rep(i, ls) {
        rep(j, lt) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                chmax(dp[i+1][j+1], dp[i][j+1]);
                chmax(dp[i+1][j+1], dp[i+1][j]);
            }
        }
    }

    string ans = "";
    ll i = (ll)s.size(), j = (ll)t.size();
    while(i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            ans = s[i-1] + ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;
}