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
using Int = long long;
#define rep(i, n) for (Int i = 0; i < n; i++)

int main() {
    Int n, k;
    cin >> n >> k;
    vector<Int> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end(), greater<Int>());
    Int ans=1e15;
    rep(i, n-k+1) {
        ans = min(ans, h[i]-h[i+k-1]);
    }
    cout << ans << endl;
}