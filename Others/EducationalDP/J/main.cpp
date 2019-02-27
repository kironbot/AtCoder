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
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll n;

double dp[310][310][310];
double rec(ll i, ll j, ll k) {
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    if (i==0 && j==0 && k==0) return 0.0;

    double res = 0.0;
    if (i > 0) res += rec(i-1, j, k) * i;
    if (j > 0) res += rec(i+1, j-1, k) * j;
    if (k > 0) res += rec(i, j+1, k-1) * k;
    res += n;
    res *= 1.0 / (i + j + k);
    return dp[i][j][k] = res;
}


int main() {
    cin >> n;
    ll a=0, b=0, c=0;
    rep(i, n) {
        ll tmp;
        cin >> tmp;
        if (tmp == 1) a++;
        else if (tmp == 2) b++;
        else c++;
    }
    memset(dp, -1, sizeof(dp));
    cout.precision(10);
    cout << rec(a, b, c) << endl;
}
