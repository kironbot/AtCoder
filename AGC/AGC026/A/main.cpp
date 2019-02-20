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
    vector<int> a(n);
    cin >> a[0];
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i-1] == a[i]) {
            ans++;
            a[i] = -1;
        }
    }
    cout << ans << endl;
}
