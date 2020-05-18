#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    int ans=0;
    int c[n], d[n];
    for (int k=0; k<30; k++) {
        ll tmp = 0;
        ll t = 1ll << k;
        for (int i=0; i<n; i++) {
            c[i] = a[i] % (2 * t);
            d[i] = b[i] % (2 * t);
        }
        sort(d, d+n);
        for (int i=0; i<n; i++) {
            tmp += lower_bound(d, d+n, 2*t-c[i]) - lower_bound(d, d+n, t-c[i]);
            tmp += lower_bound(d, d+n, 4*t-c[i]) - lower_bound(d, d+n, 3*t-c[i]);
        }
        if (tmp % 2 == 1) ans += t;
    }
    cout << ans << endl;
}
