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
    int n, t, a;
    cin >> n >> t >> a;
    int h;
    double dif = 1e18;
    int ans = 0;
    for (int i=0; i<n; i++) {
        cin >> h;
        if (abs(a - t + h * 0.006) < dif) {
            dif = abs(a - t + h * 0.006);
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
