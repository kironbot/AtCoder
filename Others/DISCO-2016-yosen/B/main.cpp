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
    ll R, N, M;
    cin >> R >> N >> M;
    double d = 2.0 * R / N;
    double ans = 0;
    for (int i = 1; i <= N + M -1; i++) {
        int j = i - M;
        double L1 = sqrt(max(0.0, R*R - (R - i*d)*(R - i*d)));
        double L2 = sqrt(max(0.0, R*R - (R - j*d)*(R - j*d)));
        ans += max(L1, L2);
    }
    cout.precision(20);
    cout << ans * 2 << endl;
}
