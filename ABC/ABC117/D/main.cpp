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
typedef long long LL;

int main() {
    LL n, k;
    vector<LL> a;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        LL tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    LL ans = 0;

    if (k == 0 || k == 1) {
        for (int x = 0; x <= k; x++) {
            LL tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (a[j] ^ x);
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
        return 0;
    }

    int start = (int)log2(k);
    for (int i = start; i>=0; i--) {
        LL bekihigh = 1 << (i+1);
        LL bekilow = 1 << i;
        LL cnt1 = 0;
        for (int j=0; j<n; j++) {
            if (a[j] % bekihigh >= bekilow) cnt1++;
        }
        ans += max(cnt1, n - cnt1) * bekilow;
        k -= bekilow;
    }

    cout << ans << endl;
}
