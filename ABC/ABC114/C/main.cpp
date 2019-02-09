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

ll n, ans=0;
void dfs(ll x, int mask) {
    if(x > n) return;
    if(mask==7) ans++;
    dfs(10*x+3, mask|1);
    dfs(10*x+5, mask|2);
    dfs(10*x+7, mask|4);
}

int main() {
    cin >> n;
    dfs(0, 0);
    cout << ans << endl; 
}
