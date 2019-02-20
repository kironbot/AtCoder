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
    int n[4];
    rep(i, 4) cin >> n[i];
    sort(n, n+4);
    if(n[0]==1 && n[1]==4 && n[2]==7 && n[3]==9) cout << "YES\n";
    else cout << "NO\n";
}
