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
    int n, T, c, t;
    int minc = 1001;

    cin >> n >> T;
    for (int i=0; i<n; i++) {
        cin >> c >> t;
        if (t <= T) minc = min(minc, c);
    }

    if (minc == 1001) puts("TLE");
    else cout << minc << endl;
}
